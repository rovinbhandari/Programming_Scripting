using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

# define PI 3.14159265
# define MOD 1000000007

int n;
vector<int> adj[20010];
int vis[20010];
int ans[20010];
long long int cnt;
  
bool bfs(int n) {
    int i,j,lev,len,v2;
    queue< pair<int,int> > q;
    pair<int,int> p;
    
    lev=0;
    q.push(make_pair(n,0));
    vis[n]=1;
    ans[n]=lev;
    while(!q.empty()) {
         p=q.front();
         q.pop();
         if(p.second==0) lev=1; else lev=0;
         len=adj[p.first].size();
         for(i=0;i<len;i++)
         {
                 v2=adj[p.first][i];
                 if(!vis[v2]) { q.push(make_pair(v2,lev)); vis[v2]=1; ans[v2]=lev; }
                 else
                 {
                     if(lev!=ans[v2])
                          return false;
                 }
                 //else { cnt--; return; }
         }   
    }
    return true;
}                   
     
int main() {
    int i,j,t,x,k;
    long long output;
    scanf("%d",&t);
    while(t--) {
         output=1;
         scanf("%d",&n);
         cnt=0;
         for(i=0;i<n;i++) { adj[i].clear(); vis[i]=0; }
         for(i=0;i<n;i++) {
              scanf("%d",&k);
              while(k--) {
                   scanf("%d",&x);
                   adj[i].push_back(x);
                   adj[x].push_back(i);
              }
         }
         
         for(i=0;i<n;i++) {
                  if(!vis[i]) { 
                       if(bfs(i))
                            output=(output*2)%MOD;
                       else 
                       {
                            output=0;
                            break;
                       }
                       
                       //cout<<i<<"   loop"<<endl;
                  }
         }
         if(n==0) output=0;
         //cout<<cnt;
         printf("%lld\n",output);
    }
    return 0;
}
                                
               
    
