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
	int t, n, m, cnt;
	LL l[100005],x,y,z,val;
	t=GI;
	while(t--)
	{
		cnt=0;val=0;
		n=GI; m=GI;
		REP(i,0,n)
		{
			l[i]=GI;
		}
		REP(i,0,m)
		{
			x=GI; y=GI; z=GI;
			val = max(val,x*x+y*y+z*z);
		}
		REP(i,0,n)
		{
			if(l[i]*l[i]<=val)
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}


