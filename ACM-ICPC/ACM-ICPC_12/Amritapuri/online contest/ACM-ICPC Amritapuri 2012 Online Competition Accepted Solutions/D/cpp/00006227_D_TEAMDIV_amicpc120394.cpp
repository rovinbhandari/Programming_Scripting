#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;i++)
#define FOR(i,a,n) for(int i=(int)a;i<(int)n;i++)
#define FOR1(i,n) for(int i=1;i<=(int)n;i++)
#define ALL(c) c.begin(),c.end()
#define FORE(it,c) for(typeof(c.begin()) it=c.begin();it!=c.end();it++)

typedef long long int lli;
typedef pair<int,int> ii;

const int N = 20010;
vector<int> E[N];
int C[N];
bool V[N];

bool dfs(int i, int color = 0){
    if(C[i] != -1){
        if(C[i] == color) return false;
    }
    C[i] = 1 - color;
    
    if(V[i]) return true;
    V[i] = 1;
    
    bool ret = true;
    REP(j,E[i].size()) 
        ret &= dfs(E[i][j], C[i]);
        
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        
        REP(i,n) E[i].clear();
        memset(V,0,sizeof(V));
        memset(C,-1,sizeof(C));
        
        REP(i,n){            
            int k;
            cin >> k;
            int v;
            REP(j,k){
                cin >> v;
                E[i].push_back(v);
                E[v].push_back(i);
            }
        }
        bool pos = 1;
        int comps = 0;
        REP(i,n){
            if(!V[i]){
                comps++;
                pos &= dfs(i);
            }
        }
        
        
        lli ans = 1;
        if(pos) {
            const lli MOD = 1e9 + 7;
            REP(i,comps) {
                ans *= 2;
                if(ans >= MOD)
                    ans %= MOD;
            }
        }
        else ans = 0;
        
        
        cout << ans << "\n";
    }
    
    
    return 0;
}