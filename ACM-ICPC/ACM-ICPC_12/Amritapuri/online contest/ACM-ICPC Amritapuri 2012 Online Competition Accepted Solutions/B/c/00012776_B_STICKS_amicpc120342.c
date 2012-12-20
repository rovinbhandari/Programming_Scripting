#include<stdio.h>
int main()
{
        long long int t,l[200000],n,m,a,b,c,i,mx,d,ll,ans;
        scanf("%lld",&t);
        while(t--)
        {
                scanf("%lld %lld",&n,&m);
                for(i=0;i<n;i++)
                        scanf("%lld",&l[i]);
                mx = 0;
                for(i=0;i<m;i++)
                {
                        scanf("%lld %lld %lld",&a,&b,&c);
                        a *=a;
                        b *=b;
                        c *=c;
                        d = a+b+c;
                        if(mx<d)
                                mx = d;
                }
                //printf("%d\n",mx);
                ans = 0;
                for(i = 0;i<n;i++)
                {
                        ll = l[i];
                        ll *=ll;
                        if(ll<=mx)
                                ans++;
                }
                printf("%lld\n",ans);
        }
        return 0;
}