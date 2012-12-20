#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long long cp,max,i,t,n,m,l[55000],a[55000],b[55000],c[55000];
    long long d[55000];
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
        for(i=0;i<m;i++)
        {
            d[i]=sqrtl(a[i]*a[i]+b[i]*b[i]+c[i]*c[i]);
        }
        max=0;
        for(i=0;i<m;i++)
        {
            if(d[i]>max)
            max=d[i];
        }
        cp=0;
        for(i=0;i<n;i++)
        {
            if(l[i]<=max)
            cp++;
        }
//        for(i=0;i<n;i++)
//        {
//            if(l[i]==max)
//            {
//                cp+=1;
//                break;
//            }
//        }
        printf("%lld\n",cp);
    }
return 0;
}
