#include<iostream>
#include<stdio.h>
#define MX 1000000

using namespace std;

int A[1100], CC[MX+10];
long long int ans;

int main() 
{
    int t,n,i,j,k;    
    scanf("%d",&t);
    while(t--)
    {
        int i,j,k,n,l,h,ll,hh;
        for(i=1;i<=MX;i++)
            CC[i]=0;
        scanf("%d%d%d",&n,&l,&h);
        ans = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&A[i]);
            CC[A[i]]++;
        }
        for(i=2;i<=MX;i++)
            CC[i]+=CC[i-1];
        CC[0]=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(j==i)
                    continue;
                ll=l-A[i]-A[j]-1;
                hh=h-A[i]-A[j];
                if(ll<0)
                    ll=0;
                if(hh<0)
                    hh=0;
                ans += (CC[hh]-CC[ll]);
                if(A[i]>ll && A[i]<=hh)
                    ans--;
                if(A[j]>ll && A[j]<=hh)
                    ans--;
                //cout<<i<<" "<<j<<" "<<ans<<"\n";
            }
            ans/=6;
            printf("%lld\n",ans);
    }
	return 0;
}
