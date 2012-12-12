#include<iostream>
#include<queue>
#include<sstream>
#include<cstdio>
#define MOD 1000000007LL
#define pb push_back
#define LL long long


using namespace std;
vector<vector<int> > adj;

struct vertex
{
       int num;
       int color;
       bool visited;
};
typedef struct vertex Vertex;

vector<Vertex> v;      
int bfs(int i)
{
     queue<int> q;
     q.push(i);
     v[i].visited=true;
     
     v[i].color=0;
     
     while(!q.empty())
     {
         i=q.front();
         vector<int> vi=adj[i];
         q.pop();
         
         for(int j=0;j<vi.size();j++)
         {
                 int cur=vi[j];
                 if(v[cur].color==v[i].color) return -1;
                 if(!v[cur].visited){ q.push(cur); v[cur].visited=true; v[cur].color=v[i].color^1;}
         }       
     }
     return 2;
}     
                              
int main()
{
    LL cases;
    scanf("%lld",&cases);
    while(cases--)
    {
                  
                  
                  int N;
                  scanf("%d",&N);                  
                  adj.resize(20010);
                  for(int i=0;i<N;i++)
                  {
                          Vertex temp;
                          temp.num=i;
                          temp.visited=false;
                          temp.color=-1;
                          v.pb(temp);
                  }        
                  for(int i=0;i<N;i++)
                  {
                          int no,temp;
                          scanf("%d",&no);
                          
                          vector<int> vi;
                          vi=adj[i];                
                          for(int j=0;j<no;j++)
                          {
                                  scanf("%d",&temp);
                                  vi.pb(temp);
                                  vector<int> vj;
                                  vj=adj[temp];
                                  vj.pb(i);
                                  adj[temp]=vj;
                          }
                          adj[i]=vi;        
                          
                  }
                  LL ans=1;
                  for(int i=0;i<N;i++)
                  {
                          if(!v[i].visited)
                          {
                                           
                                           int cur=bfs(i);
                                           if(cur==-1) 
                                           {
                                                      ans=0;
                                                      break;
                                           }                                                     
                                           else
                                               ans=(ans*cur)%MOD;
                                               
                                               
                          }
                                    
                                                                
                  }                  
                  printf("%lld\n",ans);
                  adj.resize(0);                   
                  v.resize(0);
                          
       }
       return 0;
}       
