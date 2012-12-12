#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;

#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >


void precompute(void)
{
}

LL t,n,m,i,j,d1,d2,d3,ans,maxi,l[100000];
int main()
{
	precompute();
	while(scanf("%lld",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%lld%lld",&n,&m);
			for(i=0;i<n;i++)
			{
				scanf("%lld",&l[i]);
				l[i]*=l[i];
			}
			maxi=0;
			for(j=0;j<m;j++)
			{
				scanf("%lld%lld%lld",&d1,&d2,&d3);
				maxi=max(maxi,d1*d1+d2*d2+d3*d3);
			}
			ans=0;
			for(i=0;i<n;i++)
			{
				if(maxi>=l[i])
					ans++;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
