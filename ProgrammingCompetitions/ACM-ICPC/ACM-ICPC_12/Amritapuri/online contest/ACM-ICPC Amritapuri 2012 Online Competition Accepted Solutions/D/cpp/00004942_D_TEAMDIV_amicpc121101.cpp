#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>


using namespace std;

#define FOR(i,a,b) for(int i=int(a); i<=int(b); i++)
#define REP(i,n) for(int i=0; i<int(n); i++)
typedef long long ll;

const int MAX = 20009;
vector<int> L[MAX];
int q[MAX], level[MAX], N;
bool visited[MAX];

bool bfs(int vv) {
	if(visited[vv]) return true;
	
	level[vv]=0;
	int h=1,t=1,u,v;
	q[1]=vv;
	while(h<=t) {
		u=q[h]; h++;
		REP(i,L[u].size()) {
			v = L[u][i];
			if(!visited[v]) {
				level[v]=level[u]+1;
				visited[v]=1;
				t++; q[t]=v;
			}
			else {
				if(level[u]==level[v]) return false;
			}
		}
	}
	return true;
}

int main() {
	int T; scanf("%d", &T);
	
	while(T--) {
		scanf("%d", &N);
		REP(i,N) L[i].clear();
		REP(i,N) {
			int k,u; scanf("%d", &k);
			REP(j,k) {
				scanf("%d", &u);
				L[i].push_back(u);
				L[u].push_back(i);
			}
		}
		
		memset(visited,0,sizeof(visited));
		memset(level,-1,sizeof(level));
		
		int ans = 0;
		bool possible = true;
		REP(i,N) {
			if(!visited[i]) {
				if(bfs(i)) ans++;
				else possible=false;
			}
		}
		
		if(!possible) {
			printf("0\n");
		}
		else {
			int ret = 1ll;
			int mod = 1000000007;
			REP(i,ans) {
				ret = (ret*2)%mod;
			}
			printf("%d\n", ret);
		}
	}

	return 0;
}
