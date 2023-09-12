#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
long long int t,n,l[50005],m,a[50005],b[50005],c[50005],i,j,ans;
double dia,sum,maxi;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
              scanf("%lld%lld",&n,&m);
              for(i=1;i<=n;i++)
              scanf("%lld",&l[i]);
              //scanf("%d",&m);
              maxi=0.0;
              for(i=1;i<=m;i++)
              {
                               scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
                               sum=a[i]*a[i]+b[i]*b[i]+c[i]*c[i];
                               if(sum>maxi)
                               maxi=sum;
              }
              ans=0;
              for(i=1;i<=n;i++)
              {
                               if(maxi>=l[i]*l[i])
                               ans++;
              }
              printf("%lld\n",ans);
    }
}
              
              
              
