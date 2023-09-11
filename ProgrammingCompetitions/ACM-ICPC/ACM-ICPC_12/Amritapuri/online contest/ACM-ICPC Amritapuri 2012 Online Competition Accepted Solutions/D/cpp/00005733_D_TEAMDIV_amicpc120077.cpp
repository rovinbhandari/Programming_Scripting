// Author : Segment3

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<vector>
#include<map>
#define LLD long long int
#define MOD 1000000007
using namespace std;
bool vis[20006];
int vis2[20006];
vector<int> V[20006];
bool iscycle;
int n,k,r;

LLD mypow(LLD a,LLD b)
{
	if(b==0)
		return 1;
        LLD ans = 1;
	LLD pre = a%MOD;

	while(b!=0)
	{
		if(b%2==1)
			ans = (ans*pre)%MOD;
		pre = (pre*pre)%MOD;
		b=b/2;
	}
	return ans%MOD;
}

void dfs(int idx)
{
	vis[idx]=true;
	int i;

	int sz = V[idx].size();
	for(i=0;i<sz;i++)
	{
		if(!vis[V[idx][i]])
		{
			dfs(V[idx][i]);
		}
	}
}

void cycle(int idx, int num)
{
	vis2[idx]=num;
	int sz = V[idx].size();
	int i;
	for(i=0;i<sz;i++)
	{
		int k = vis2[V[idx][i]];
		if(k)
		{
			if( (abs(k-num)+1)%2 == 1)
			{
				iscycle = true;
				return;
			}
		}
		else
		{
			cycle(V[idx][i],num+1);
			if(iscycle)
				return;
		}
	}
	return;

}


int main()
{
	int i,j,t;
	scanf("%d",&t);
	while(t--)
	{
		long long int ans=0;
		iscycle=false;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			vis[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			for(j=0;j<k;j++)
			{
				scanf("%d",&r);
				V[i].push_back(r);
				V[r].push_back(i);
			}
		}

		int c=0;
		for(i=0;i<n;i++)
		{
			if(!vis[i])
			{
				c++;
				dfs(i);
			}
		}


		for(i=0;i<n;i++)
			vis2[i]=0;
	         for(i=0;i<n;i++)
		{
			if(!vis2[i])
				cycle(i,1);
			if(iscycle)
			{
				ans=0;
				break;
			}
		}
		
		if(!iscycle)
		  ans = mypow(2,c);

		printf("%lld\n",ans);

		for(i=0;i<=n;i++)
			V[i].clear();
	}


	return 0;

}
