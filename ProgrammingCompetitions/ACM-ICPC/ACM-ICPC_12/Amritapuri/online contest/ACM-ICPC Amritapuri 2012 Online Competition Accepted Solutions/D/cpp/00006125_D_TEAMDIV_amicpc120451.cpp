#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;

#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()

typedef long long LL;
const int INF = 1000000000;
const LL INFLL = LL(INF) * LL(INF);
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }

vector<vector<int> > graph;
vector<int> vis;

const long long int M=1000000007;

struct node
{
    int c,i;
    node(int a,int b)
    {
        i=a;
        c=b;
    }
};

long long int mod_exp(long long int a,long long int b,long long int m)
{
    if(b==0)
    {
        return 1LL;
    }
    else if(b==1)
    {
        return a%m;
    }
    else
    {
        long long int temp=mod_exp(a,b/2,m);
        return (((temp*temp)%m)*mod_exp(a,b%2,m))%m;
    }
}

int main()
{
    //freopen("ip.txt","r",stdin);

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        //cout<<n<<"\n";
        graph.clear();
        graph.resize(n);
        vis.clear();
        vis.resize(n,-1);
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            //cout<<k<<"\n";
            for(int j=0;j<k;j++)
            {
                int x;
                scanf("%d",&x);
                graph[i].push_back(x);
                graph[x].push_back(i);
            }
            //cout<<"donee\n";
        }
        /*cout<<"n:- "<<n<<"\n";
        for(int i=0;i<n;i++)
        {
            cout<<"\n";
            for(int j=0;j<graph[i].size();j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        bool poss=1;
        int comp=0;
        for(int i=0;i<n;i++)
        {
            //cout<<vis[i]<<" ";
            if(vis[i]==-1)
            {
                comp++;
                queue<node> bfs;
                node s(i,0);
                bfs.push(s);
                while(!bfs.empty())
                {
                    node temp=bfs.front();
                    bfs.pop();
                    vis[temp.i]=temp.c;
                    //cout<<"i "<<temp.i<<"\n";
                    for(int j=0;j<graph[temp.i].size();j++)
                    {
                        //cout<<"j "<<graph[temp.i][j]<<" color "<<vis[graph[temp.i][j]]<<"\n";
                        if(vis[graph[temp.i][j]]==temp.c)
                        {
                            //cout<<"wrong: "<<temp.i<<" "<<graph[temp.i][j]<<"\n";
                            poss=0;
                            break;
                        }
                        else if(vis[graph[temp.i][j]]==-1)
                        {
                            node x(graph[temp.i][j],!temp.c);
                            bfs.push(x);
                        }
                    }
                }
                if(!poss)
                {
                    break;
                }
            }
        }
        //cout<<"\n";
        //printf("comp:- %d %d\n",comp,poss);
        if(poss)
        {
            printf("%lld\n",mod_exp(2,comp,M));
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}

