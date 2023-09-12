#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t,count=0;
    cin>>t;
    int x=t;
    long n,m,i,fit[t];
    while(x--)
    {
             cin>>n;
             cin>>m;
             long int s[n],a[m],b[m],c[m];
             for(i=0;i<n;i++)       
                  cin>>s[i];
             for(i=0;i<m;i++)
             {       
                  cin>>a[i];
                  cin>>b[i];
                  cin>>c[i];
             }
             int result[m],temp=0;
             for(i=0;i<m;i++)
             {
                 result[i]=(int)sqrt((a[i]*a[i])+(b[i]*b[i])+(c[i]*c[i]));
                 if(temp<result[i])
                    temp=result[i];
                    
             }
             
             for(i=0;i<n;i++)          
             {
                 if(s[i]<=temp)
                 {
                              count++;
                 }
             }                 
    fit[x]=count;
    count=0;
    }
    for(i=t-1;i>=0;i--)
       cout<<fit[i]<<endl;
//    system("pause");
    return 0;
}
    
