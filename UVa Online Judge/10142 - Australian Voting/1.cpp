#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

typedef unsigned int ui;

struct candidate
{
	string name;
	ui firstchoices;
	vector<vector<ui> > ballots;

	candidate()
	{
		name = string();
		firstchoices = 0;
		ballots = vector<vector<ui> >();
	}
	
	candidate(string _name, ui _firstchoices, vector<vector<ui> > _ballots)
	{
		name = _name;
		firstchoices = _firstchoices;
		ballots = _ballots;
	}

	static bool comparator(const candidate& a, const candidate& b)
	{
		return a.firstchoices < b.firstchoices;
	}

	void print()
	{
		cerr << "name = " << name
			 << endl
			 << "firstchoices = " << firstchoices
			 << endl
			 << "ballots = ";
		for(int i = 0; i < ballots.size(); i++)
		{
			for(int j = 0; j < ballots[i].size(); j++)
				cerr << ballots[i][j] << " ";
			cerr << "; ";
		}
		cerr << endl;
	}
};

string winner(map<ui, candidate>& m)
{
	map<ui, candidate>::iterator mit = m.begin();
	while(mit != m.end())
	{
		#ifdef DBG
		cerr << "id = " << mit->first
			 << endl;
		mit->second.print();
		#endif
		mit++;
	}
	return "zobo";
}

int main(void)
{
	ui t, n, b, i, j;
	vector<ui> bi;
	char s[82];
	char c;

	scanf("%u", &t);
	while(t--)
	{
		scanf("%u", &n);
		getchar();
		map<ui, candidate> idc;
		for(i = 1; i <= n; i++)
		{
			fgets(s, 80, stdin);
			#ifdef DBG
			fprintf(stderr, "s = %s\n", s);
			cerr << "string(s) = " << string(s) << endl;
			#endif
			idc[i] = candidate(string(s), 0, vector<vector<ui> >());
		}
		
		bi.clear();
		readballots:
		scanf("%u", &b);
		c = getchar();
		if(c == ' ')
		{
			bi.push_back(b);
			for(i = 1; i < n; i++)
			{
				scanf("%u", &b);
				bi.push_back(b);
			}
			idc[bi[0]].firstchoices++;
			idc[bi[0]].ballots.push_back(bi);
			bi.clear();
			c = getchar();
		}
		if(c == '\n')
		{
			c = getchar();
			if(c == '\n' || c == EOF)
			{	
				if(n == 1)
				{
					bi.push_back(b);
					idc[bi[0]].firstchoices++;
					idc[bi[0]].ballots.push_back(bi);
				}
				cout << winner(idc) << endl;
			}
			else
			{
				ungetc(c, stdin);
				if(n == 1)
				{
					bi.push_back(b);
					idc[bi[0]].firstchoices++;
					idc[bi[0]].ballots.push_back(bi);
					bi.clear();
				}
				goto readballots;
			}
		}
	}
	return 0;
}
