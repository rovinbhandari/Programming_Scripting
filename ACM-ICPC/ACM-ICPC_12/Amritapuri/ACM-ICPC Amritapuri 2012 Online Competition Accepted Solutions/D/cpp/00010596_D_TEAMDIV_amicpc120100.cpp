
// This works!!
//Data-structures includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<list>

//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<limits.h>

using namespace std;

#define s(n)		scanf("%d",&n)
#define sf(n) 		scanf("%lf",&n)
#define ss(n) 		scanf("%s",n)
#define pb		push_back
#define mp	 	make_pair
#define fill(a,v) 	memset(a, v, sizeof(a))
#define SZ(v)		(int)(v.size())
#define all(x)		x.begin(), x.end()
#define INDEX(arr,ind)	(lower_bound(all(arr),ind)-arr.begin())
#define FF		first
#define SS		second
#define EPS		1e-9
#define INF		(int)1e9
#define LINF		(long long)1e18
#define FOR(i,a,b)	for(int i=a;i<b;i++)
#define REP(i,n)	FOR(i,0,n)
#define T(t)            int t;scanf ("%d",&t);while (t--)

typedef vector<int> VI;
typedef priority_queue<int> MXHEAP;
typedef priority_queue<int,VI,greater<int> > MNHEAP;
typedef vector<vector<int> > VVI;
typedef long long int LL;
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
typedef pair<double,double> PDD;
#define M 1000000007
VVI v1(20006);
bool vis[20006];
int cl[20006];
bool dfs( int i1, int cl1)
{
	if(vis[i1] && cl1==1-cl[i1])
		return false;
	if(vis[i1])
		return true;
	vis[i1]=true;
	cl[i1]=cl1;
	int i;
	for(i=0;i<v1[i1].size();i++)
	{

		if(!dfs(v1[i1][i],1-cl1))
			return false;
	}
	return true;
}
int main()
{
	T(t)
	{
	int n,ct,i,x,k,j;
	s(n);
	for(i=0;i<n;i++)
		v1[i].clear();
	for(i=0;i<n;i++)
	{
		s(k);
		for(j=0;j<k;j++)
		{
			s(x);
			v1[i].pb(x);
			v1[x].pb(i);
		}
	}
	ct=1;
	memset(vis,false,sizeof(vis));
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			if(!dfs(i,0))
			{
				break;
			}
			else
				ct=(ct*2)%M;
		}
	}
	if(i<n)
		cout << 0 << endl;
	else
		cout << ct << endl;
	}
	return 0;
}
