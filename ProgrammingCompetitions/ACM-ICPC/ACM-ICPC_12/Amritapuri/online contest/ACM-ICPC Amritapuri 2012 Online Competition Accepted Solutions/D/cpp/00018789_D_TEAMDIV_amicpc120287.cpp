#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <climits>
#include <cfloat>
#include <cassert>
#define readint(n)      scanf("%d",&n)
#define readull(n)      scanf("%llu",&n)
#define readll(n)       scanf("%lld",&n)
#define readf(n)        scanf("%f",&n)
#define readd(n)        scanf("%lf",&n)
#define init(mem)       memset(mem,0,sizeof(mem))
#define ll              long long int
#define ull             unsigned long long int
using namespace std;
#define mod 1000000007

struct node{
    int parent;
    int index;
    node(){}
    node(int p,int i){
        parent=p;
        index=i;
    }
};


int main(){
    int t,n,m,val;
    bool* present=new bool[20001];
    int* level=new int[20001];

    vector<int> *neigh=new vector<int>[20001];
    readint(t);
    while(t--){
        readint(n);
        for(int i=0;i<n;i++){
            neigh[i].clear();
        }

        for(int i=0;i<n;i++){
            readint(m);
            for(int j=0;j<m;j++){
                readint(val);
                if(i==val) continue;
                neigh[i].push_back(val);
                neigh[val].push_back(i);
            }
        }

        for(int i=0;i<n;i++){
            sort(neigh[i].begin(),neigh[i].end());
            vector<int> tmp;
            if(neigh[i].size()>0){
                tmp.push_back(neigh[i][0]);
                for(int j=1;j<neigh[i].size();j++){
                    if(neigh[i][j]!=neigh[i][j-1]){
                        tmp.push_back(neigh[i][j]);
                    }
                }
            }
            neigh[i]=tmp;
            #ifdef db
            cout<<"\n";
            for(int k=0;k<neigh[i].size();k++){
                cout<<neigh[i][k]<<" ";
            }
            cout<<endl;
            #endif
        }
        // all things in place

        init(present);
        bool ok=1;
        ll count=1;
        for(int i=0;i<n;i++){
            level[i]=-1;
        }
        for(int i=0;i<n;i++){
            if(level[i]!=-1) continue;

            level[i]=0;
            queue<int>q;
            q.push(i);
            
            #ifdef db
            cout<<"------------------\n";
            #endif
            while(q.size()>0){
                int curr=q.front();
                q.pop();
                #ifdef db
                cout<<curr<<endl;
                #endif

                for(int j=0;j<neigh[curr].size();j++){
                    //cout<<"1";
                    if(!ok) break;
                    if(level[neigh[curr][j]]==-1){
                        level[neigh[curr][j]]=(level[curr]+1)%2;
                        q.push(neigh[curr][j]);
                    }
                    else if((level[neigh[curr][j]]-level[curr])%2==0){
                        ok=false;
                        #ifdef db
                        cout<<"break at "<<curr<<" "<<neigh[curr][j]<<endl;
                        #endif
                        break;
                    }
                }
                if(!ok) break;
            }
            if(!ok) break;
            else{
                count=(2*count)%mod;
            }
        }
        if(!ok){
            printf("0\n");
        }
        else{
            printf("%lld\n",count);
        }
    }
    return 0;
}