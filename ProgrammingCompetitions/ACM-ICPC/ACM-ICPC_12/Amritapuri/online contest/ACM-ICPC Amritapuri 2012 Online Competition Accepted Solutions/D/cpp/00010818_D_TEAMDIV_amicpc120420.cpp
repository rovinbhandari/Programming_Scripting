#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000

int numberVertex, numberEdges;
int particion[MAX], visited[MAX];
vector< int > adjacencyMatrix[MAX];

bool bfs(int begin)
{
    int i, origin, destination;
    queue< int > queueVertex;
    queueVertex.push(begin);
    particion[begin] = 1; // 1 left,
    visited[begin] = 1; // set adjacencyMatrixray

    while(!queueVertex.empty())
    {
        origin = queueVertex.front(); queueVertex.pop();
        for(i=0; i < adjacencyMatrix[origin].size(); i++)
        {
            destination = adjacencyMatrix[origin][i];
            if(particion[origin] == particion[destination])
            {
                return false;
            }
            if(visited[destination] == 0)
            {
                visited[destination] = 1;
                particion[destination] = 3 - particion[origin]; // alter 1 and 2 subsets
                queueVertex.push(destination);
            }
        }
    }
    return true;
}

bool is_bipartite()
{
    int count=0;
    for(int i=0; i< numberVertex; i++)
    {
        if(visited[i]==0)
            count++;
       if (visited[i] == 0 && !bfs(i)) {
           return false;
       }
    } 
    //cout<<"count "<<count<<"\n";
    //cout<<(((1LL)<<count)%1000000007)<<"\n";
    long long co=1;
    for(int i=0;i<count;i++){
        co=(co*2);
        co=(co>=1000000007)?(co-1000000007):co;
    }

    cout<<co<<"\n";
    return true;
}

#define s(n) scanf("%d",&n)
int main()
{
    //freopen("tarea2.in", "r", stdin);
    int t;
    s(t);
    for(int i=0;i<t;i++){
        int n;
        s(n);
        numberVertex=n;
        //cout<<n<<"\n";
        int sum=0;
        for(int j=0;j<n;j++){
            int d,e;
            s(d);
            //sum+=d;
            //cout<<d<<"\n";
            for(int k=0;k<d;k++){
                //cout<<"reading";
                s(e);
                //cout<<e<<"\n";
                //printf("here\n");
                adjacencyMatrix[j].push_back(e);
                adjacencyMatrix[e].push_back(j);
            }
        }
        sum=0;
        for(int j=0;j<n;j++){
             vector<int>::iterator it;

            sort(adjacencyMatrix[j].begin(), adjacencyMatrix[j].end() );
            it=std::unique( adjacencyMatrix[j].begin(), adjacencyMatrix[j].end() );
            adjacencyMatrix[j].resize( it - adjacencyMatrix[j].begin() ); 

            sum+=adjacencyMatrix[j].size();
            //debug(adjacencyMatrix[j]);
        }
       
        numberEdges=sum/2;
        //cout<<"numEdges "<<numberEdges<<"\n";
        if(is_bipartite()) {
        }
        else {cout<<"0\n";}
        particion[MAX], visited[MAX];
        for(int j=0;j<MAX;j++){adjacencyMatrix[j].clear();particion[j]=0; visited[j]=0;}
        }
        

    return 0;
}