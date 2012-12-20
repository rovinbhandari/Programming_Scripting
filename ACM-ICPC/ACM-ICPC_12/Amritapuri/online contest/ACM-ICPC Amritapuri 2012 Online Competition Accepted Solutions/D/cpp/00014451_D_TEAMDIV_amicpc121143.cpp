/*Team Decision*/

#include<cstdio>
#include<cstring>
#include<set>
#include<stack>

using namespace std;

char visited[20000];
int parent[20000];
set<int> adj[20000];

int dfs(int);
int modpow(int,int);

int main()
{
	int count,i,index,j,K,N,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
			adj[i].clear();
		for(i=0;i<N;i++)
		{
			scanf("%d",&K);
			for(j=0;j<K;j++)
			{
				scanf("%d",&index);
				adj[i].insert(index);
				adj[index].insert(i);
			}
		}
		count=dfs(N);
		if(count==-1)
			printf("0\n");
		else
			printf("%d\n",modpow(2,count));
	}
	return 0;
}

int dfs(int N)
{
	int count,i,j;
	stack<int> s;
	set<int>::iterator iter;
	memset(visited,0,sizeof(char)*N);
	memset(parent,-1,sizeof(int)*N);
	count=0;
	for(i=0;i<N;i++)
	{
		if(!visited[i])
		{
			visited[i]=1;
			parent[i]=-1;
			s.push(i);
			while(!s.empty())
			{
				j=s.top();
				s.pop();
				for(iter=adj[j].begin();iter!=adj[j].end();iter++)
				{
					if(!visited[*iter])
					{
						visited[*iter]=1;
						parent[*iter]=j;
						s.push(*iter);
					}
					else
					{
						if(adj[j].find(parent[*iter])!=adj[j].end())
							return -1;
					}
				}
			}
			count++;
		}
	}
	return count;
}

int modpow(int a,int b)
{
	int product,psequence;
	product=1;
	psequence=a;
	while(b>0)
	{
		if(b&1)
			product=(1LL*product*psequence)%1000000007;
		b>>=1;
		psequence=(1LL*psequence*psequence)%1000000007;
	}
	return product;
}