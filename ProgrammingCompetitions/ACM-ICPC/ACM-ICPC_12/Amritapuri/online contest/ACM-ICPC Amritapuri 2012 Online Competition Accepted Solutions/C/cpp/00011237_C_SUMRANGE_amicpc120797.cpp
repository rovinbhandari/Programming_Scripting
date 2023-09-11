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
	int t, n, l, h, a[1005],j,p;
	LL cnt;
	t=GI;
	while(t--)
	{
		cnt=0;
		n=GI; l=GI; h=GI;
		REP(i,0,n)	
			a[i]=GI;
		sort(a,a+n);
		REP(i,0,n-2)
		{
			j=i+1;
			p=i+1;
			for(int k=n-1;k>i+1;k--)
			{
				for(;j<k;j++)
				{
					if(a[i]+a[j]+a[k]>=l)
						break;
				}
				for(;p<k;p++)
				{
					if(a[i]+a[p]+a[k]>h)
						break;
				}
				if(p>i+1)
					p--;
				if(a[i]+a[j]+a[k]>=l && a[i]+a[p]+a[k]<=h && j<=p && j>i)
					cnt+=(p-j+1);
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}


