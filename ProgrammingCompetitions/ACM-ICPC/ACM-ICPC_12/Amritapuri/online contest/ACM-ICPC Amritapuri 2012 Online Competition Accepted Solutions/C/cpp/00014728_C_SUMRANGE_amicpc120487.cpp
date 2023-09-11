using namespace std;

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define INF 1<<30
#define LL long long
#define pb push_back

int n,l,h,cnt;
vector<int> v;
vector<int> :: iterator low,high;

int  binary(int sum,int start)
{
   
   low = lower_bound(v.begin()+start,v.end(),l-sum);
   high = upper_bound(v.begin()+start,v.end(),h-sum);
   
  
   cnt+=int(high-low);
   //cout<<"b "<<cnt<<endl;
   
   
}
int  binary2(int sum,int start)
{
   
   high = upper_bound(v.begin()+start,v.end(),h-sum);
   
  
   cnt+=int(high-(v.begin()+start));
   //cout<<"c "<<cnt<<endl;
   
   
}
int main()
{
    int t,sum,temp;
     cin>>t;
    while(t--)
    {
              v.clear();
              cnt=0;
              scanf("%d%d%d",&n,&l,&h);
              for(int i=0;i<n;i++)
              {
                      
                 scanf("%d",&temp);
                 v.pb(temp);
              }
    
              sort(v.begin(),v.end());
              
            
   
              for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++)
                {
                        sum=v[i]+v[j];
                        if(sum>=h)
                          break;
                          
                        if(sum<l && sum<h)
                        {
                            binary(sum,j+1);
                                 
                        }
                        else if(sum>=l && sum<h)
                         {
                             binary2(sum,j+1);
                         }
                }
              
              cout<<cnt<<endl;
    }

//system("pause");
return 0;
}
