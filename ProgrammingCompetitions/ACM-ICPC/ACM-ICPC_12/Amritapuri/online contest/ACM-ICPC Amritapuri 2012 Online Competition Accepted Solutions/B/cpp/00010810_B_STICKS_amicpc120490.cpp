#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    long long int t,i,j,k,count,x,y,z,n,m;
    cin>>t;
    while(t--)
    {
             cin>>n>>m;
            long long int a[n],b[m],l=0,d;
             count=0;
             for(i=0;i<n;i++)
             cin>>a[i];
             for(i=0;i<m;i++)
             {cin>>x>>y>>z;
             d=sqrt(x*x+y*y+z*z);
             if(l<d)
             l=d;
             }
             for(i=0;i<n;i++)
             {
                             if(a[i]<=l)
                             count++;
             }
             cout<<count<<"\n";
    }
    return 0;
    
    
}
    
