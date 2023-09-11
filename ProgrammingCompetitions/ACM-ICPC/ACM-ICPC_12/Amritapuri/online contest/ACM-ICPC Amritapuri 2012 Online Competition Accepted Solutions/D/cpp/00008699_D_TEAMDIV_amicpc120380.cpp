#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
typedef long long ll;

#define MAXN 20010
vector<int> G[MAXN];
int color[MAXN];
bool ok;

void dfs(int u, int c) {
	
	if(color[u] != -1) {
		if(color[u] != c) ok = 0;
		return ;
	}
	
	color[u] = c;
	
	REP(i, G[u].size()) {
		dfs(G[u][i], !c);
	}
}

const ll MOD = 1000000007;
void cmod(ll &x) {
	if(x >= MOD) x %= MOD;
}

int main() {
	
	int nt; scanf("%d", &nt); while(nt--) {
		int n, cnt, tmp; 
		
		scanf("%d", &n); 
		REP(i,n) {
            G[i].clear();
        }
        
		REP(i,n) {	
			scanf("%d", &cnt);
			while(cnt--) {
				scanf("%d", &tmp);
				G[i].push_back(tmp);
				G[tmp].push_back(i);
			}
		}
		
		
		
		ok = 1;
		memset(color, -1, sizeof color); 
		
		ll ans = 1;
		
		REP(i,n) {
			if(color[i] == -1) {
				dfs(i, 0); 
				ans = (ans * 2);	
			}
			
			if(!ok) break;
			cmod(ans);
		}
		
		if(!ok) printf("0\n"); 
		else printf("%lld\n", ans);
		
    }
	return 0;
}


