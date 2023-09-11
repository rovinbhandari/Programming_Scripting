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
	ui id;
	string name;
	ui firstchoices;
	vector<vector<ui> > ballots;

	candidate()
	{
		id = 0;
		name = string();
		firstchoices = 0;
		ballots = vector<vector<ui> >();
	}
	
	candidate(ui _id, string _name, ui _firstchoices,
				vector<vector<ui> > _ballots)
	{
		id = _id;
		name = _name;
		firstchoices = _firstchoices;
		ballots = _ballots;
	}

	static bool comparatorfirstchoices(const candidate& a, const candidate& b)
	{
		return a.firstchoices < b.firstchoices;
	}

	static bool comparatorid(const candidate& a, const candidate& b)
	{
		return a.id < b.id;
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
		cerr << endl << "###" << endl;
	}
};

ui n;
candidate arraycandidate[20];

bool winner(map<ui, candidate>& m)
{
	int i = 0;
	map<ui, candidate>::iterator mit = m.begin();
	while(mit != m.end())
	{
		#ifdef DBG
		cerr << "id = " << mit->first
			 << endl;
		mit->second.print();
		#endif
		arraycandidate[i] = mit->second;
		i++;
		mit++;
	}

	//TODO: n is not proper to use.
	sort(&arraycandidate[0], &arraycandidate[n],
					candidate::comparatorfirstchoices);
	#ifdef DBG
	for(i = 0; i < n; i++)
		arraycandidate[i].print();
	#endif
	for(i = n - 1; i > 0; i--)
		if(arraycandidate[i].firstchoices > arraycandidate[i - 1].firstchoices)
			break;
	if(i == n - 2)	// => unique majority => 1 winner
	{
		cout << arraycandidate[i].name;
		return true;
	}
	else if(i == 0)	// => all tied => n winners
	{
		sort(&arraycandidate[0], &arraycandidate[n],
					candidate::comparatorid);
		for(i = 0; i < n; i++)
			cout << arraycandidate[i].name;
		return true;
	}
	else			// => no winner(s) yet
	{
		//remove all the last tied candidates and add their votes to the \
		  second preference candidates.
		for(; i >= 0; i--)
		{
			// iterate over the ballots of candidate i.
				// increment all the second preferences by 1.
				// delete the first preference. // think about using lists.
				// copy the remaining into that of second preference.
			for(int j = 0; j < arraycandidate[i].ballots.size(); j++)
			{
				m[arraycandidate[i].ballots[j][1]].firstchoices++;
				// TODO: check how many elemets are contained in it.
				m[arraycandidate[i].ballots[j][1]].ballots.push_back(
						vector<ui>(arraycandidate[i].ballots[j].begin() + 1,
								   arraycandidate[i].ballots[j].end()));
			}
			// remove candidate i from the map.
			m.erase(arraycandidate[i].id);
		}
		return false;
	}
}

int main(void)
{
	ui t, b, i, j;
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
			idc[i] = candidate(i, string(s), 0, vector<vector<ui> >());
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
				while(!winner(idc));
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
