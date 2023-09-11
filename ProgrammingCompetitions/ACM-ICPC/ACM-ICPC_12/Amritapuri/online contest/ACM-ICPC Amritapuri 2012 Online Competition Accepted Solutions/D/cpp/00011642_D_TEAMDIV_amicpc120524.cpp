#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <cstdio>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <cassert>

typedef unsigned long long ULL;
typedef long long LL;

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define ABS(a) ((a>0)?a:-a))

#define SS(a) scanf("%d",&a)
#define SZ(a) ((int)a.size())
#define PB(a) push_back(a)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,(int)(n-1))
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define printv(v) REP(i,SZ(v))printf("%d ",v[i]);
#define mp(a,b) make_pair(a,b)
#define PII pair<int,int>
#define MOD 1000000007

using namespace std;


int color[22222];
bool seen[22222];

LL pow2(LL exp,LL n){
    LL res = 1;
    while(n)
    {
        if (n&1){
            res *= exp;
            res %= MOD;
        }
        exp *= exp;
        exp %= MOD;
        n /= 2;
    }
    return res%MOD;
}

int main()
{
 //freopen("input.txt","r",stdin);
 int t;
 scanf("%d",&t);
 while(t--)
 {
    int n;
    scanf("%d",&n);
    vector <int> adj[n];
    REP(i,n)
    {
        int temp;
        scanf("%d",&temp);
        REP(j,temp){
            int x;
        scanf("%d",&x);
        adj[i].PB(x);
        adj[x].PB(i);
        }
    }

    REP(i,n) {
        color[i] = -1;
        seen[i] = false;
    }

    bool flag = true;
    int cnt = 0;

    REP(i,n)
    {
        if (!seen[i]){
            cnt++;
            queue <int> Q;
            Q.push(i);
            seen[i] = true;
            color[i] = 0;
            while(!Q.empty()){

                int node = Q.front();
                Q.pop();

                REP(k,SZ(adj[node])){
                    int neigh = adj[node][k];
                    if (seen[neigh]) {
                        if (color[neigh]==color[node]) {
                            flag = false;
                            goto label;
                        }
                    }
                    else{
                    seen[neigh] = true;
                    color[neigh] = !color[node];
                    Q.push(neigh);
                    }
                }

            }

        }
    }

    label:
    if (!flag) printf("%d\n",0);
    else printf("%lld\n",pow2(2LL,(LL)cnt));
 }

return 0;
}


