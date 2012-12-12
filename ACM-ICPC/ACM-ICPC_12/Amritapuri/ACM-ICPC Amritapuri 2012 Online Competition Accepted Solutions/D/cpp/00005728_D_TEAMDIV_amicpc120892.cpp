#include <stdio.h>
#include <vector>
#include <queue>

#define MAXN 20010
#define MOD 1000000007

using namespace std;

int main()
{
	int i, j, k, T, n, m, idx;
	scanf("%d", &T);

	vector< int> graph[MAXN];
	queue <int> q;

	int vis[MAXN];

	while(T--)
	{
		for(i=0; i<MAXN; i++)
			graph[i].clear();
		for(i=0; i<MAXN; i++)
			vis[i]=0;
		scanf("%d", &n);
		for(i=0;i<n;i++)
		{
			scanf("%d", &k);
			for(j=0;j<k;j++)
			{
				scanf("%d", &m);
				graph[i].push_back(m);
				graph[m].push_back(i);
			}
		}

		long long ans = 1LL;
		bool brk=false;
		while(!q.empty())
			q.pop();

		for(i=0; i<n; i++)
		{
			if(vis[i]==0)
			{
				q.push(i);
				vis[i]=1;
				ans = (ans*2)%MOD;
				while(!q.empty())
				{
					idx = q.front();
					q.pop();
					for(j=0; j<graph[idx].size();j++)
					{
						k = graph[idx][j];
						if(vis[idx]==vis[k])
						{
							ans = 0LL;
							brk = true;
							break;
						}
						else if(vis[k]==0)
						{
							vis[k] = -vis[idx];
							q.push(k);
						}
					}
					if(brk)
						break;
				}
			}
			if(brk)
				break;
		}
		printf("%lld\n", ans);

	}

	return 0;
}
