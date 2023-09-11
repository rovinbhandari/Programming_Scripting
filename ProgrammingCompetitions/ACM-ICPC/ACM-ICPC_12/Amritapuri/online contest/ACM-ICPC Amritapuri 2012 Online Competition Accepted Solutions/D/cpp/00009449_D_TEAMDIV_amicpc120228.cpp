#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <climits>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>
#include <fstream>

using namespace std;

#define PB push_back
#define MP make_pair
#define INF (int)1e9
#define F first
#define S second
#define MOD 1000000007LL

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef pair<int,int> PI;
typedef pair<int,pair<int,int> > TI;

#define LIM 20000+5

int N,M;
LL ans=1;
bool** mat;
bool vis[LIM];
int id[LIM];
bool clash;

LL powermod(int n)
{
    LL ret=1,inter=2;
    while(n){
        if(n&1){
            ret *= inter;
            ret %= MOD;
        }
        inter *= inter;
        inter %= MOD;
        n = n>>1;
    }
    return ret;
}

void func(int node)
{
    queue<PI> myq;
    myq.push(MP(node,0));
    vis[node]=true;
    id[node]=0;
    while(!myq.empty()){
        int curr=myq.front().F;
        int step=myq.front().S;
        myq.pop();
        for(int i=0;i<N;i++){
            if(mat[curr][i]==0) continue;
            int now=i;
            if(vis[now]){
                 if(id[now]==id[curr]) clash=true;
            }
            else{
                vis[now]=true;
                id[now]=(step+1)%2;
                myq.push(MP(now,id[now]));
            }
        }
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d", &N);

        mat = new bool*[N];
        for(int i=0;i<N;++i) mat[i] = new bool[N];
        for(int i=0;i<N;++i) for(int j=0;j<N;++j) mat[i][j] = 0;

        //R.clear();
        //R.resize(N);
        for(int i=0;i<N;i++){
            scanf("%d", &M);
            //R[i].resize(M);
            int foo;
            for(int j=0;j<M;j++){
                scanf("%d", &foo);
                mat[i][foo]=mat[foo][i]=1;
            }
        }
        int teams=0;
        clash=false;
        for(int i=0;i<N;i++) vis[i]=false,id[i]=-1;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                teams++;
                func(i);
            }
        }
        if(clash) printf("0\n");
        else printf("%lld\n", powermod(teams));
    }
    return 0;
}
