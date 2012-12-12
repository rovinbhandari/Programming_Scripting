#include<stdio.h>
int main()
{
    long long int t,i,m,n,a[50002],b[50002],c[50002],l[50002],co,len,max;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&l[i]);
        }
        for(i=0;i<m;i++)
        {
            scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
        }
        max=0;
        for(i=0;i<m;i++)
        {
            len=a[i]*a[i]+b[i]*b[i]+c[i]*c[i];
            if(len>max)
            max=len;
        }
     //   printf("%d\n",max);
        co=0;
        for(i=0;i<n;i++)
        {
            if(l[i]*l[i]<=max)
            co++;
        }
        printf("%lld\n",co);
    }
    return 0;
}

