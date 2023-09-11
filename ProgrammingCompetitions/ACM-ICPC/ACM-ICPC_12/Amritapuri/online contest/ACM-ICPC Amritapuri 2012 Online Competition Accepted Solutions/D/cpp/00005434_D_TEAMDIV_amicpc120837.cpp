#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define N 20000
#define MOD 1000000007

bool color[N];
bool visited[N];
bool poss;

vector <int> adj[N];

bool dfs(int u, bool c) {
	visited[u] = true;
	color[u] = c;
	for(int i = 0; i < adj[u].size(); i ++) {
		if(visited[adj[u][i]]) {
			if(color[adj[u][i]] == c) {
				poss = false;
			}
		}
		else {
			dfs(adj[u][i], !c);
		}
	}
}

int main() {
	int T;
	scanf(" %d", &T);
	while(T -- > 0) {
		int comp = 0;
		poss = true;
		int n;
		memset(visited, false, sizeof(visited));
		scanf(" %d", &n);
		for(int i = 0; i < n; i ++) {
			int k;
			scanf(" %d", &k);
			for(int j = 0; j < k; j ++) {
				int u;
				scanf(" %d", &u);
				adj[i].push_back(u);
				adj[u].push_back(i);
			}
		}
		for(int i = 0; i < n; i ++) {
			if(!visited[i]) {
				dfs(i, true);
				comp ++;
			}
			adj[i].clear();
		}
		long long ans = 1;
		if(!poss) {
			printf("0\n");
			continue;
		}
		for(int i = 0; i < comp; i ++) {
			ans = ans * 2;
			if(ans >= MOD)
				ans -= MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
