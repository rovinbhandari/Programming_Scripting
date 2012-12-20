#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#define cin(n) scanf("%d",&n)
#define pb push_back
#define push push_back
#define pop pop_back
#define mp make_pair
using namespace std;
int mod=(int)1e9+7;
vector<int> visited,color;
vector<vector<int> > arr;
vector<int> s;
int main()
{
    int t,n,k,ans,temp;
    cin(t);
    for(;t>0;t--)
    {
         ans=1;
         cin(n);
         arr.clear();
         arr.resize(n);
         visited.clear();
         visited.resize(n);
         color.clear();
         color.resize(n);
         for(int i=0;i<n;i++)color[i]=visited[i]=0;
         for(int i=0;i<n;i++)
         {
                 cin(k);
                 for(int j=0;j<k;j++)
                 { 
                         cin(temp);
                         arr[i].pb(temp);
                         arr[temp].pb(i);
                 }
         }
        // for(int i=0;i<n;i++){for(int j=0;j<arr[i].size();j++)cout<<arr[i][j]<<" ";cout<<endl;}
         for(int i=0;i<n;i++)
         {
                 if(visited[i]>0)continue; 
                 visited[i]=1;
                 color[i]=1;
                 temp=i;
                 s.clear();
                 for(int j=0;j<arr[i].size();j++)
                 {
                         color[arr[i][j]]=-1;
                         s.push(arr[i][j]);
                 }
                 while(s.size()>0)
                 { 
                                  int k=s[s.size()-1];
                                  //cout<<s.size()<<" ";
                                  s.pop();
                                  if(visited[k]>0)continue;
                                  //cout<<s.size()<<endl;
                                  visited[k]=1;
                          for(int j=0;j<arr[k].size();j++)
                          {
                                  if(temp==arr[k][j])continue;
                            if(color[k]==color[arr[k][j]])
                            { 
                               //cout<<"wrong: "<<k<<" "<<arr[k][j]<<endl;
                               ans=0;break;
                            }
                            color[arr[k][j]]=-color[k];
                            if(visited[arr[k][j]]==0)s.push(arr[k][j]);
                          }
                          temp=k;
                 }
                 ans*=2;ans%=mod;
                 if(ans==0)break;
         }
         /*
         for(int i=0;i<n;i++)
         {
                 if(visited[i]==0){
                                   ans*=2;
                                   ans%=mod;
                                   }
         }*/
         printf("%d\n",ans);
    }
    return 0;
}
