#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <sstream>
#include <list>
#include <map>
#include <queue>
#include <stack>

#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define print(x) cout<<#x<<" is "<<x<<endl;
#define inf 2000000000
#define Pair pair<int,int>
#define eps 1e-8
#define MAX 300000
#define MOD 1000000007
using namespace std;

int n;
vector<int> adj[MAX];
int col[MAX];

bool isBipartite(int i)
{
	queue<int> q;
	q.push(i);
	col[i]=0;
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		for(int j=0;j<adj[cur].size();j++)
		{
			if(col[adj[cur][j]]==-1)
			{
				q.push(adj[cur][j]);
				col[adj[cur][j]]=col[cur]==0?1:0;
			}
			else if(col[cur]==col[adj[cur][j]])
				return false;
		}
	}
	return true;
}

long long exp(int pow)
{
	if(pow==0)
		return 1;
	if(pow%2==0)
	{
		long long ans=exp(pow/2);
		return ((ans*ans)%MOD);
	}
	return (exp(pow-1)*2)%MOD;
}

int main(){
	int t,k,x;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<MAX;i++)
			adj[i].clear();
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>k;
			for(int j=0;j<k;j++)
			{
				cin>>x;
				adj[i].push_back(x);
				adj[x].push_back(i);
			}
		}
		int ans=0;
		memset(col,-1,sizeof(col));
		for(int i=0;i<n;i++)
		{
			if(col[i]==-1)
			{
				if(!isBipartite(i))
				{
					ans=0;
					break;
				}
				ans++;
			}
		}
		if(ans==0)
		{
			cout<<"0"<<endl;
			continue;
		}
		long long x=exp(ans);
		if(x<0)
			x+=MOD;
		x%=MOD;
		cout<<x<<endl;
	}
	return 0;
}