#include<iostream>
#include<vector>
using namespace std;
#define maxn 20005
#define m 1000000007

vector<int> adj[maxn+2];

long long power(int k)
{
      long long result=1,i;
      for(i=1;i<=k;i++)
            result=((result%m)*(2%m))%m;
      return(result);
}

int check_first(bool visited[],int n)
{
      int i;
      for(i=0;i<n;i++)
      {
            //cout<<visited[i]<<" ";
            if(visited[i]==0)
                  return(i);
      }
      //cout<<endl;
      return(-1);
}
int main()
{
      int cases,u,v,n,nrivals,i,j,first,popped,parent_color;
      int cnt=0,f=0,r=0,sum;
      long long ans;
      int q[maxn*2]={0};
      int color[maxn]={2};

      bool visited[maxn]={0};
      bool flag=0;
      cin>>cases;

      while(cases--)
      {
            cnt=0;f=0;r=0;
            flag=0;
            for(i=0;i<n;i++)
            {
                  adj[i].clear();
                  visited[i]=0;
            }

            cin>>n;
            for(u=0;u<n;u++)
            {
                  cin>>nrivals;
                  for(j=1;j<=nrivals;j++)
                  {
                        cin>>v;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                  }
            }

            /*for(i=0;i<n;i++)
                  cout<<"size of:"<<i<<"="<<adj[i].size()<<endl;*/
            first=0;
            while(first!=-1)
            {
                  //cout<<"first="<<first<<endl;
                  cnt++;
                  f=0;r=0;
                  for(i=0;i<maxn;i++)
                  {
                        q[i]=0;
                        color[i]=2;
                  }
                  //if(adj[first].size()>0)
                  //{
                        visited[first]=1;
                        q[f]=first;
                        color[first]=0;
                        while(f<=r)
                        {
                              //cout<<"Popped: "<<q[f]<<endl;
                              popped=q[f];
                              parent_color=color[popped];
                              for(i=0;i<adj[popped].size();i++)
                              {
                                    if(color[adj[popped][i]]==2)
                                    {
                                          if(parent_color==0)
                                                color[adj[popped][i]]=1;

                                          else if(parent_color==1)
                                                color[adj[popped][i]]=0;
                                    }
                                    else if(color[adj[popped][i]]==parent_color)
                                    {
                                          ans=0;
                                          //cout<<"Not bic\n";
                                          flag=1;
                                    }

                                    if(adj[popped][i]>=0 && visited[adj[popped][i]]==0)
                                    {
                                          r++;
                                          q[r]=adj[popped][i];
                                          //cout<<"pushed="<<q[r]<<endl;
                                          visited[adj[popped][i]]=1;
                                    }
                              }
                              f++;
                        }
                  //}
                  first=check_first(visited,n);
            }
            if(flag==0)
                  ans=power(cnt);
            cout<<ans<<endl;
      }
      return 0;
}
