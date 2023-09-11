#include<cstdio>
#include<cstdlib>
#include<cmath>
#define DG(a,b,c) (a*a)+(b*b)+(c*c)
#define MAX(a,b) ((a>b)?a:b)

long long int L[50001],A[50001],B[50001],C[50001];

int main()
{
    int t,i,j,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&L[i]);
            L[i]=L[i]*L[i];
        }
        long long int max=0;
        for(j=0;j<m;j++)
        {
            scanf("%lld %lld %lld",&A[j],&B[j],&C[j]);
            max=MAX(DG(A[j],B[j],C[j]),max);
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(L[i]<=max)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
