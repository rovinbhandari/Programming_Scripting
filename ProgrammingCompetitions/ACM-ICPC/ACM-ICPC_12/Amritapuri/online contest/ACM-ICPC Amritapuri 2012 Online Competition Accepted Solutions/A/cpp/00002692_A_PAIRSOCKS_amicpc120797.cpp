# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define GI ({int t;scanf("%d",&t);t;})
#define REP(i,a,b) for(int i=a;i<b;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS (double)(1e-9)
#define PI (double)(3.141592653589793)

int main()
{
	int t,r=0,g=0,b=0,w=0;
	string s;
	t=GI;
	while(t--)
	{
		r=0;g=0;b=0;w=0;
		cin>>s;
		REP(i,0,s.size())
		{
			if(s[i]=='R')	r+=1;
			if(s[i]=='G')	g+=1;
			if(s[i]=='B')	b+=1;
			if(s[i]=='W')	w+=1;
		}
		if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}


