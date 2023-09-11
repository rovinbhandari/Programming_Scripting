# include <iostream>
# include <cstdio>
# include <vector>
# include <set>
# include <map>
# include <bitset>
# include <algorithm>
# include <string>
# include <cstring>
# include <sstream>
# include <cstdlib>
# include <queue>
# include <stack>
using namespace std;
# define MAXN 25000
# define MOD 1000000007LL
vector<int> adj[MAXN];
int n;
bool poss;
int cnt;
int color[MAXN];
bool visited[MAXN];


long long modexp(long long int a, long long int b)
{
  long long ret = 1;
  while(true)
    {
      if(b & 1)
	ret = (ret * a) % MOD;

      a = (a * a) % MOD;
      b >>= 1;
      if(!b) break;
    }
  return ret;
}

void bfs(int src)
{
  int i,u,v;
  queue<int> q;
  q.push(src);
  bool red, blue;

  while(!q.empty())
    {
      u = q.front();
      q.pop();
      red = true;
      blue = true;
      if(visited[u]) continue;

      for(i = 0; i < adj[u].size(); i++)
	{
	  v = adj[u][i];
	  if(color[v] == 0)
	    {
	      q.push(v);
	      continue;
	    }

	  if(color[v] == 1)
	    red = false;
	  else blue = false;
	}
      
      if(red && blue)
	cnt++;
      if(!red && !blue)
	poss = false;

      if(red)
	color[u] = 1;
      if(blue)
	color[u] = 2;
      visited[u] = true;
    }
}

int main()
{
  int i,dest,src,j,sz,t;
  long long v;
  scanf("%d", &t);
  while(t--)
    {
      cnt = 0;
      poss = true;
      memset(color, 0, sizeof(color));
      scanf("%d", &n);
      for(i = 0; i < n; i++)
	{
	  src = i;
	  scanf("%d", &sz);
	  for(j = 0; j < sz; j++)
	    {
	      scanf("%d", &dest);
	      adj[src].push_back(dest);
	      adj[dest].push_back(src);
	    }
	}
      memset(visited, false, sizeof(visited));
      for(i = 0; i < n; i++)
	{
	  if(!visited[i])
	    bfs(i);
	}

      if(!poss)
	printf("0\n");
      else
	{
	  v = modexp((long long)2, (long long)cnt);
	  printf("%lld\n", (v + MOD) % MOD);
	}
      for(i = 0; i < n; i++)
	{
	  adj[i].clear();
	  //revadj[i].clear();
	}
    }

  return 0;
}
