#include <cstdio>
#include <queue>
#include <vector>
#define pb push_back
const int MOD=1000000007;
using namespace std;

int partition[20200];
int v[20200];
vector <int> adj[20200];

int expmod(int a,int b,int mod)
{
	long long x=1,y=a;
	while(b>0)
	{
		if(b&1) x=(x*y)%mod;
		y=(y*y)%mod;
		b>>=1;
	}
	return x;
}

bool bfs(int start)
{
	queue <int> q;
	partition[start]=1;
	v[start]=1;
	q.push(start);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		for(int i=0;i<adj[cur].size();i++)
		{
			if(partition[cur]==partition[adj[cur][i]]) return false;
			if(v[adj[cur][i]]==0)
			{
				v[adj[cur][i]]=1;
				partition[adj[cur][i]]=3-partition[cur];
				q.push(adj[cur][i]);
			}
		}
	}
	return true;
}
	
int main()
{
	int t,i,j,k,n,flag,kk;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<20200;i++) adj[i].clear(),partition[i]=0,v[i]=0;
		
		flag=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			for(j=0;j<k;j++)
			{
				scanf("%d",&kk);
				adj[i].pb(kk);
				adj[kk].pb(i);
			}
		}
		int ans=0;
		flag=1;
		for(i=0;i<n;i++) if(partition[i]==0)
		{
			ans++;
			if(bfs(i)==false)
			{
				flag=0; break;
			}
		}
		if(flag==0) printf("0\n");
		else
		{
			printf("%d\n",expmod(2,ans,MOD));
		}
	}
	return 0;
}