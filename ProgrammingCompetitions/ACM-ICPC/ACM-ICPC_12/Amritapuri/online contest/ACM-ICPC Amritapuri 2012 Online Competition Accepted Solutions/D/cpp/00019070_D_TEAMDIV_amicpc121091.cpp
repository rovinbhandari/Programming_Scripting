#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<iterator>
#include<string>
#include<sstream>
using namespace std;

vector<int> adj[20002];
int N,cc;
int c[20002],cn[20002];
bool vis[20002];
int two[20002];
vector<int> list;

void dfs(int u,int d){
    vis[u] = true;
    list.push_back(u);
    c[u] = d;
    cn[u] = cc;
    for(int i=0;i<adj[u].size();i++) if(!vis[adj[u][i]]) dfs(adj[u][i],(d+1)&1);
}

int main(){
    int T,x,y;
    two[0] = 1;
    for(int i=1;i<=20000;i++) two[i] = (two[i-1]*2)%1000000007;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            adj[i].clear();
            vis[i] = false;
        }
        for(int i=0;i<N;i++){
            scanf("%d",&x);
            for(int j=0;j<x;j++) scanf("%d",&y) ,adj[i].push_back(y) , adj[y].push_back(i);;
        }
        cc = 0;
        bool f = false;
        for(int i=0;i<N;i++) if(!vis[i]){
            list.clear();
            dfs(i,0);
            f = false;
            for(int j=0;j<list.size();j++){
                int u = list[j];
                for(int k=0;k<adj[u].size();k++){
                    int v = adj[u][k];
                    if(cn[v] == cn[u] && cn[v] == cc && c[u] == c[v]){
                        f = true;
                        goto end;
                    }
                }
            }
            ++cc;
        }
        printf("%d\n",two[cc]);
        end: ;
        if(f) printf("0\n");
    }
    return 0;
}
