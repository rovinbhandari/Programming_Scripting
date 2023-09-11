#include<iostream>
#include<queue>

#define VAL 1000000007

using namespace std;

int inp[20010]; 
vector <int > v[20010];
int ans[12];


int main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   
   for(int i=0;i<t;++i)
   {
      int n; cin>>n;
      for (int j=0;j<2010;++j)
      {
         inp[j]=0;
         v[j].resize(0);
      }
      
      for (int l=0;l<n;++l)
      {
         int a;
         cin>>a;
         for(int b=0;b<a;++b)
         {
            int x; cin>>x;
            v[l].push_back(x);
            v[x].push_back(l);
        
         }
      }
      //to be removed
      /*for(int d=0;d<v[0].size();++d)
      {
      	cout << v[0][d] << " ";
      }*/
      queue<int> Q;
      long long int count=1;
      int flag=0,var=0,z=0;
      for(int run=0;run<n && flag==0;++run)
      {      	
         if(inp[run]==0)
         {
            inp[run]=1;
            while(!v[run].empty())
            {
               var=v[run].back();
               v[run].pop_back();
               if(inp[var]==0)
               {
                  inp[var]=2;
                  Q.push(var);
               }
               else if(inp[var]==1)
               {
                  flag=1;
                  //cout << run << "aaa" << var << endl;
               }
            }
            while((!Q.empty()) && (flag==0))
            {
               z=Q.front();
               Q.pop();
               if(inp[z]==1)
               {
                  while(!v[z].empty())
                  {
                     var=v[z].back();
                     v[z].pop_back();
                     if(inp[var]==0)
                     {
                        inp[var]=2;
                        Q.push(var);
                     }
                     else if(inp[var]==1)
                     {
                        flag=1;
                        //cout << z << "bbb" << var << endl;
                     } 
                  }
               }
               if(inp[z]==2)
               {
                  while(!v[z].empty())
                  {
                     var=v[z].back();
                     v[z].pop_back();
                     if(inp[var]==0)
                     {
                        inp[var]=1;
                        Q.push(var);
                     }
                     else if(inp[var]==2)
                     {
                        flag=1;
                        //cout << z << "ccc" << var << endl;
                     } 
                  }
               }
            }
            if(flag==0) count=(count*2)%VAL;
         }
       }
       if (flag==1) ans[i]=0;
       else ans[i]=count;
    }     
    for(int g=0;g<t;++g)
    {
      cout << ans[g] << endl;
    }
    return 0;
 }       
