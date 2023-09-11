// Authors : The_Iterators
#include <cstdio>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define MOD 1000000007LL
#define MAX 20002
using namespace std;
int N;
int V[MAX];
vector<int> ADJ[MAX];
// check if any odd length cycles
int comp = 0;
bool dfs_odd(int idx, int prev, int cnt) {
    V[idx] = cnt; // color this
    // dont visit the previous
    int ret = 0;
    for(int i=0;i<ADJ[idx].size();i++) {
        int v = ADJ[idx][i];
        if(v != prev) {
            if(V[v] == -1) {
                // if it has not been previously visited
                if(!dfs_odd(v, idx, (cnt+1)%2)) {
                    return 0; // if it fails, return 0
                }
            }
            else {
                // if something is being visited again with (cnt+1)%2 == 0
                if((cnt+1)%2 != V[v]) {
                    // its a problem return 0
                    return 0; // cant be visited
                }
            }
        }
    }
    return 1;
}

void dfs(int vtx) {
    V[vtx] = 1;
    for(int i=0;i<ADJ[vtx].size();i++) {
        if(!V[ADJ[vtx][i]]) {
            dfs(ADJ[vtx][i]);
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        memset(V, -1, sizeof V);
        scanf("%d",&N);
        for(int i=0;i<N;i++)
            ADJ[i].clear();
        for(int i=0;i<N;i++) {
            int K;
            scanf("%d",&K);
            for(int j=0;j<K;j++) {
                int v;
                scanf("%d",&v);
                ADJ[i].push_back(v);
                ADJ[v].push_back(i); // here symmetricity doesn't matter
            }
        }
        long long ans = 1;
        for(int i=0;i<N;i++) {
            if(V[i] == -1) {
                bool ret = dfs_odd(i, -1, 0);
                if(ret == 0) {
                    ans = 0;
                    break;
                }
            }
        }
        if(ans == 0) {
            printf("0\n");
            continue;
        }
        memset(V, 0, sizeof V);
        int cnt = 0;
        for(int i=0;i<N;i++) {
            if(!V[i]) {
                cnt++;
                dfs(i);
            }
        }
        for(int i=0;i<cnt;i++) {
            ans = (ans * 2)%MOD;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
