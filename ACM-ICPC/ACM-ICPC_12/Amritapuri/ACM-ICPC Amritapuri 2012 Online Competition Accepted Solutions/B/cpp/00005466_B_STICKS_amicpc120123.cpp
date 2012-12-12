#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        long long int l[50005];
        long long int a[50005] , b[50005] , c[50005] ;
        
        for(int i=0; i<n; i++)
            scanf("%lld",&l[i]);
        long long int max=0;
        long long int x,y;
        for(int i=0; i<m; i++)
        {
            scanf("%lld",&a[i]);
            scanf("%lld",&b[i]);
            scanf("%lld",&c[i]);
            x = a[i]*a[i] + b[i]*b[i] + c[i]*c[i];
            if(x>max)
                max=x;
        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            y = l[i]*l[i];
            if(y <= max)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
