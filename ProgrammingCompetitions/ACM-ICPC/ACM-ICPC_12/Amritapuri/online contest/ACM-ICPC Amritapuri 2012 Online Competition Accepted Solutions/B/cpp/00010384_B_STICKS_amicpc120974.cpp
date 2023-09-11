#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;

int main()
{
    int t,n,m,i,ans,j;
    ll st[50000],a[50000],b[50000],c[50000],cm,mp;

    scanf("%d",&t);
    while(t--)
    {
        //memset(h,0,sizeof(h));
        ans=0;
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++)
            scanf("%lld",&st[i]);
        sort(st,st+n);
        mp=-1;
        for(i=0; i<m; i++)
        {
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
            cm=(sqrt(a[i]*a[i]+b[i]*b[i]+c[i]*c[i]));
            mp=max(cm,mp);
        }
        //printf("mp:%lld\n",mp);
        for(j=0; j<n; j++)
            if(mp>=st[j])
            {
                ans++;
            }
            else
                break;

        printf("%d\n",ans);

    }
    return 0;
}



