/*
ID: nihcas700
LANG: C++
*/

# include <iostream>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cstdio>
# include <algorithm>
# include <vector>
# include <map>
# include <set>
# include <list>
# include <deque>
# include <new>
# include <stack>
# include <queue>
# include <iterator>
# include <functional>
# include <fstream>

 
using namespace std;


# define scd(x) scanf("%d",&x)
# define prd(x) printf("%d",x)
# define scf(x) scanf("%f",&x)
# define prf(x) printf("%f",x)
# define scs(x) scanf("%s",x)
# define prs(x) printf("%s",x)
# define prn() printf("\n")
# define inf 2000000000

int main()
{
	int t;
	string s;
	scd(t);
	
	while(t--)
	{
		int r=0,b=0,g=0, w = 0;
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			
			if(s[i]=='R')
				r++;
			else if(s[i] == 'B')
				b++;
			else if(s[i] == 'G')
				g++;
			else
				w++;
		}
		cout << ((r % 2 == 0 && b % 2 == 0 && g % 2 == 0 && w % 2 == 0) ? "YES" : "NO") << "\n";
	}
	
	
	return 0;
}
