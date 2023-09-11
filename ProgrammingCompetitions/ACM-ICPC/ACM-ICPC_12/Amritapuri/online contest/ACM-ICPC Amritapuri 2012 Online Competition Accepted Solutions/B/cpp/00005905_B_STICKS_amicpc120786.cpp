#include<iostream>
#include<math.h>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    long long int t,i,j,n,m,cnt;
    scanf("%lld",&t);
    while(t--)
    {
      scanf("%lld%lld",&n,&m);
      long long int l[n],a[m],b[m],c[m];
      cnt=0;
      long long int z,max=-1;
      for(i=0;i<n;++i)
      scanf("%lld",&l[i]);
      for(i=0;i<m;++i)
      scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
      for(i=0;i<m;++i)
      {
        z=(long long int)sqrt((a[i]*a[i])+(b[i]*b[i])+(c[i]*c[i]));
        if(z>max)
        max=z;
        }
        for(i=0;i<n;++i)
        {
            if(l[i]<=max)
            cnt++;
        }
            printf("%lld\n",cnt);
            }
            return 0;
            }
