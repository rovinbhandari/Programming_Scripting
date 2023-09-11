#include <iostream>
#include <string>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	
	int i = 0, j=0;
	
	int r=0,g=0,b=0,w=0;
	string s;
	for (i=0;i<tc;i++)
	{
	    string s;
		cin >> s;
		
		r=0;
		g=0;
		b=0;
		w=0;
		for (j=0;j<s.length();j++)
		{
			if (s[j] == 'R')
				r++;
			else if (s[j] == 'G')
				g++;
			else if (s[j] == 'B')
				b++;
			else if (s[j] == 'W')
				w++;
		}
		
		if ((r % 2 == 0) && (g % 2 == 0) && (b % 2 == 0) && (w % 2 == 0))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
