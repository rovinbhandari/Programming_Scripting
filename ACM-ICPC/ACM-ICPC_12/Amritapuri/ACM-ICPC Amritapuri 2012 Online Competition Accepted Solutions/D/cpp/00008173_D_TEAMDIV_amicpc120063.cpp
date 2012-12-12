
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<climits>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

#define REP(i,s,n)  for (int i=(s),_n=(n);i<=_n;i++)
#define FOR(i,s,n)  for (int i=(s),_n=(n);i<_n;i++)
#define REPD(i,e,s)  for (int i=(e),_s=(s);i>=_s;i--)
#define tr(container, it) \
		        for (typeof(container.begin()) it=container.begin(); it!=container.end();it++)
#define PB push_back

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

LL MOD=1000000007;
VI gr[20010];
int vis[20010];

int bfs(int n) {
	vis[n]=0;
	queue<int> Q;
	Q.push(n);
	while (!Q.empty()) {
		int cur=Q.front();
		Q.pop();
		int ll=gr[cur].size();
		for(int i=0;i<ll;i++) {
			if (vis[gr[cur][i]]==-1) {
				Q.push(gr[cur][i]);
				vis[gr[cur][i]]=1-vis[cur];
			}
			if (vis[gr[cur][i]]!=1-vis[cur]) {
				return 0;
			}
		}
	}
	return 2;
}

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		for (int i=0;i<20010;i++) {
			gr[i].clear();
			vis[i]=-1;
		}
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			int k;
			scanf("%d",&k);
			while (k--) {
				int tmp;
				scanf("%d",&tmp);
				gr[i].PB(tmp);
				gr[tmp].PB(i);
			}
		}
		LL ans=1;
		for (int i=0;i<n;i++) {
			if (vis[i]==-1) {
				ans=(ans*(LL)bfs(i))%MOD;
				if (ans==0) break;
			}
		}
		if(n==0)
			ans=0;
		printf("%lld\n",ans);
	}
	return 0;
}
