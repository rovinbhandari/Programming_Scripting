using namespace std;
#include <cmath>
#include <cstdio>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
typedef long long ll; 
typedef pair<int,int> pii; 
#define FOR(i,n) for (int i = 0; i < n; i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define MP make_pair
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)
#define split(str) {vs.clear();istringstream ss(str);while(ss>>(str))vs.push_back(str);}
#define PI 3.141592653589793
#define MOD 1000000007
ll binpow (ll a, ll n) 
{
  ll res = 1;
  while (n) 
  {
    if (n & 1)
      res *= a;
    if(res>=MOD)res=res%MOD;
    a *= a;
    a=a%MOD;
    n >>= 1;
  }
  return res%MOD;
}
int main()
{
  int t;
  sf(t);
  while(t--)
  {
    
    int n;
    sf(n);
    vector<int> g[n];
    FOR(i,n)
    {
      int a;
      sf(a);
      FOR(j,a)
      {
	int x;
	sf(x);
	g[i].PB(x);
	g[x].PB(i);
      }
    }
    vector<int> level(n,-1);
    
    int count=0;
    bool cycle=false;
    FOR(i,n)
    {
      if(level[i]<0)
      {
	queue<int> q;
	//q.clear();
	q.push(i);
	level[i]=0;
	while(!q.empty())
	{
	  int a=q.front();
	  q.pop();
	  FOR(j,g[a].size())
	  {
	    if(level[g[a][j]]<0)
	    {q.push(g[a][j]);level[g[a][j]]=level[a]+1;}
	    else if(level[g[a][j]]==level[a])
	    {
	      cycle=true;
	      break;
	    }
	  }
	  if(cycle)break;
	}
	//cout<<i<<endl;
	count++;
      }
      if(cycle)break;
    }
    //cout<<count<<endl;
    if(cycle)cout<<"0"<<endl;
    else
      cout<<binpow(2,count)<<endl;
  }
}