// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>

//Data Structures
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
using namespace std;

#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)

typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
int n,l,h;
int a[1010];
int main()
{
	int i,j,t;
	for(si(t);t--;)
	{	
		si(n);
		si(l);
		si(h);
		for(i=0;i<n;i++)
			si(a[i]);
		sort(a,a+n);
		int x,y,g,f,c=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				x=l-a[i]-a[j];
				y=h-a[i]-a[j];
				g=lower_bound(a+j+1,a+n,x)-a;
				f=upper_bound(a+j+1,a+n,y)-a;
				c+=(f-g);
			}
		}
		pil(c);
	}
	return 0;
}

