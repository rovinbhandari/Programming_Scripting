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
#define mod 1000000007
int vis[20001];
int col[20001];
VVI q;
int dfs(int v,int c)
{
	int x;
	rep(i,sz(q[v]))
	{
		if(!vis[q[v][i]])
		{
			vis[q[v][i]]=1;
			col[q[v][i]]=1-c;
			x = dfs(q[v][i],1-c);
			if(x==-1)
				return -1;
		}
		else
		{
			if((1-c)!=col[q[v][i]])
				return -1;
		}
	}
	return 1;
}
int main()
{
	int i,j,n,t,m,x,y;
	for(si(t);t--;)
	{
		si(n);
		q.clear();
		fill(vis,0);
		fill(col,0);
		q.resize(n);
		rep(i,n)
		{
			si(m);
			rep(j,m)
			{
				si(x);
				q[i].pb(x);
				q[x].pb(i);
			}
		}
		int flag=0;
		LL ans=1;
		rep(i,n)
		{
			if(!vis[i])
			{
				vis[i]=1;
				col[i]=0;
				j=dfs(i,0);
				if(j==-1)
				{
					flag=1;
					break;
				}
				else
				{
					ans= (ans*2)%mod;		
				}
			}
		}
		if(flag)
			cout << 0 << endl;
		else
			cout << ans%mod << endl;
		
	}
	return 0;
}

