#include<cstdio>
#include<math.h>
int main()
{
    long double l[50001],b[50001],h[50001];
    long double c[50001],d[50001],e[50001],f[50001];
    long int count=0,tot=0;
    int t;
    long int i,j;
    long int n,m;
    long double le[50001];
    scanf("%d",&t);
    while(t--)
    {
     count=0;tot=0;         
     scanf("%ld %ld",&n,&m);
     for(i=0;i<n;i++)
                     scanf("%llf",&le[i]);
     for(i=0;i<m;i++)
                     scanf("%llf %llf %llf",&l[i],&b[i],&h[i]);
     for(i=0;i<m;i++)
     {
                 c[i]=(long double)(sqrt((l[i]*l[i])+(b[i]*b[i])));
                 d[i]=(long double)(sqrt((l[i]*l[i])+(h[i]*h[i])));
                 e[i]=(long double)(sqrt((b[i]*b[i])+(h[i]*h[i])));
                 f[i]=(long double)(sqrt((h[i]*h[i])+(c[i]*c[i])));
     }
     j=0;
     /*for(j=0;j<n&&count<=n;j++)
     {
         count=0;
         for(i=0;i<m;i++)
         {
                 //printf("Before:le[%ld]=%llf count=%ld\n",j,le[j],count);
                 
                 //printf("c=%llf d=%llf e=%llf f=%llf\n",c,d,e);
                 if(le[j]<=l[i]||le[j]<=b[i]||le[j]<=h[i]||le[j]<=c[i]||le[j]<=d[i]||le[j]<=e[i]||le[j]<=f[i])
                 {
                                ++count;++tot;
                 }
                 //printf("le[%ld]=%llf tot=%ld\n",j,le[j],tot);
                 if(count>0)
                    break;
         }
     }*/
     long double max=f[0];
     for(i=0;i<m;i++)
     {
         if(f[i]>max)
            max=f[i];
     }
     for(i=0;i<n;i++)
     {
         if(le[i]<=max)
            ++tot;
     }
     
     printf("%ld\n",tot);
    }
    return 0;
}
    
                     
                     
