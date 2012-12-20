#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              long long int n,m;
              //cin>>n>>m;
              scanf("%lld%lld",&n,&m);
              long long int arr[n];
              for(int i=0;i<n;i++)
              scanf("%lld",&arr[i]);
              long long int count=0,ma=0;
              for(int i=0;i<m;i++)
              {
                      long long int a,b,c;
                      scanf("%lld%lld%lld",&a,&b,&c);
                      long long int mi=sqrt(a*a + b*b + c*c);
                      ma=max(ma,mi);
              }
              for(int j=0;j<n;j++)
                      {
                             // cout<<sqrt(a*a+b*b)<<endl;
                              if(arr[j]<=ma)
                              {                count++;
                                               // check[j]=1;
                              }
                      }
              //cout<<count<<endl;
              printf("%lld\n",count);
    }
    return 0;
}
