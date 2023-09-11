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
#define LL long long int
#define VI vector < int >
#define PII pair < int , int >

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,i,j,k;
		scanf("%d%d",&n,&m);
		LL a[n],b[4][m];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		LL max=0;
		for(i=0;i<m;i++)
		{
			long long int l1,l2,l3;
			scanf("%lld %lld %lld",&l1,&l2,&l3);
			long long int ctr=l1*l1 + l2*l2 +l3*l3;
			if(ctr > max)
				max=ctr;
		}
		int ans=0;
		for(i=0;i<n;i++)
		{
			if(a[i]*a[i] <= max)
				ans++;
		}
		printf("%d\n",ans);

	}
	return 0;
}
