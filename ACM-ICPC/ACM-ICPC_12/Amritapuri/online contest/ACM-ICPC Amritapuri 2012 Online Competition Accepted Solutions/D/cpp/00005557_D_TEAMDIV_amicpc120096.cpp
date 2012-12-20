
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <queue>
#include <cassert>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define in(n) scanf("%d",&n)
#define inl(n) scanf("%lld",&n)
#define out(n) printf("%d ",n)
#define outln(n) printf("%d\n",n)
#define outl(n) printf("%lld ",n)
#define outlln(n) printf("%lld\n",n)
#define LL long long 
#define pb push_back
#define f first
#define s second

using namespace std;
#define maxn 20200
int N;
int vis[maxn];
vector<int> g[maxn];

int nc(int c) {
    if(c==1)return 2;
    return 1;
}

int dfs(int u, int co) {
    vis[u] = co;
    //cout<<u<<" : "<<co<<endl;
    for(int i=0;i<g[u].size();i++) {
        int v = g[u][i];
        //cout<<"ALL u = "<<u<<", v="<<v<<endl;
        if(vis[v]==0) {
            //cout<<"u = "<<u<<", v="<<v<<endl;
            int vv = dfs(v, nc(co));
            if(vv==-1)
                return -1;
        }
        else if(vis[v] == co)
            return -1;
        else if(vis[v] == nc(co))
            continue;
    }
    return 1;
}


#define mod 1000000007

LL modpow(LL ba, int exp) {
    if(exp == 0)return 1LL;
    LL tmp = modpow(ba, exp>>1);
    tmp = tmp*tmp;
    if(tmp >= mod)tmp%=mod;
    if(exp & 1)tmp *= ba;
    if(tmp >= mod)tmp%=mod;
    return tmp;
}

int main()
{
    int T;
    in(T);
    while(T--) {
        memset(vis, 0, sizeof vis);
        in(N);
        rep(i,0,N)
            g[i].clear();
        for(int i=0;i<N;i++) {
            int k;
            in(k);
            rep(j,0,k) {
                int x;
                in(x);
                g[i].pb(x);
                g[x].pb(i);
            }
        }
        int pw = 0;
        bool fl = true;
        for(int i=0;i<N;i++) {
            int val = 1;
            if(vis[i] == 0) {
                pw++;
                val = dfs(i, 1);
            }
            //cout<<"i,val = "<<i<<","<<val<<endl;
            if(val == -1)
            {
                fl = false;
                break;
            }
        }
        if(!fl) puts("0");
        else {
            LL ans = modpow(2, pw);
            printf("%lld\n", ans);
        }

    }
    return 0;
}
