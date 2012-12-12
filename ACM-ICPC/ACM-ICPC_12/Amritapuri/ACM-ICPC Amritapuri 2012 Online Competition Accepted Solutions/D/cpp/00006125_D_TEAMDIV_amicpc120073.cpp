
/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)	
#define mod 1000000007
#define MAXN 1000010
#define MP make_pair
#define INF mod

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;
vector<vector<int> > a;
int vis[40000];

int dfs(int cur,int col){
	if(vis[cur]!=0){
		if(col!=vis[cur])
			return 0;
		return 2;
	}
	vis[cur]=col;
	for(int i=0;i<a[cur].size();i++)
		if(dfs(a[cur][i],3-col)==0)
			return 0;
	return 2;

}
int main(){
	int i,n,t,x,g,ans,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		a.clear();
		a.resize(30000);
		ans=1;
		for(i=1;i<=n;i++){
			scanf("%d",&g);
			for(j=1;j<=g;j++){
				scanf("%d",&x);
				x++;
				a[i].PB(x);
				a[x].PB(i);
			}
		}
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++){
			if(vis[i]==0){
				ans*=dfs(i,1);
				if(ans>=mod)
				ans%=mod;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
