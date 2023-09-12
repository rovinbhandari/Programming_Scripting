#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#include<iterator>

#include<set>
#define MOD 1000000007

using namespace std;
int color[20000];
bool error;
struct node{
    long id;
    int color;
    node(long i, int col){
        id = i;
        color = col;
    }
};

void colorit(long in, vector < set<long> >& adj){
   //try coloring with 1 
    node root(in, 1);
    color[in] = 1;
    stack<node> rec;
    rec.push(root);
    while(!rec.empty() && !error){
        node index = rec.top();
        rec.pop();
        long mat_id = index.id;
        set<long> arbit = adj[index.id];
        set<long>::iterator it;

        for(it = arbit.begin();it != arbit.end();it++){
            if(color[*it] != 0){
                if(color[*it] == index.color){
                    error = true;
                break;
                }
            }
            else{
                int other_color;
                if(index.color == 1)
                    other_color = 2;
                if(index.color == 2)
                    other_color = 1;
                node newnode(*it, other_color);
                color[*it] = other_color;
                rec.push(newnode);
            }
        }
    }
}






int main(){
    int t;
    cin>>t;
    while(t--){
        long N;
        error = false;
        cin>>N;
        memset(color, 0, sizeof(color));
        vector< set<long> > adj(N, set<long>());
        for(long i=0;i<N;i++){
            long rivals;
            cin>>rivals;
            vector<long> a;
            for(long j = 0;j<rivals;j++){
                long a;
                cin>>a;
                adj[i].insert(a);
                adj[a].insert(i);
            }
        }
        long long ways = 1;

        for(long i =0;i < N;i++){
            if(!error && color[i] == 0){
                ways = (ways * 2) % MOD;
                colorit(i, adj);
            }
            else if(error){
                ways = 0;
                break;
            }
        }
        cout<<ways<<endl;
    }
}


