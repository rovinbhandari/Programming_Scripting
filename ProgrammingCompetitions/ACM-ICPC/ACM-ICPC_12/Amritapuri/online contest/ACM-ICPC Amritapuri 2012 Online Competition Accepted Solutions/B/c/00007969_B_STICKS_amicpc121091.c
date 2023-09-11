# include<stdio.h>
# include<stdlib.h>
# include<math.h>
int n,m,p,i;
long long a[50001][3],c,d,l[50001];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        p=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        scanf("%lld",&l[i]);
        for(i=0;i<m;i++)
        scanf("%lld %lld %lld",&a[i][0],&a[i][1],&a[i][2]);
        c=0;
        for(i=0;i<m;i++)
        {
            d=a[i][0]*a[i][0]+a[i][1]*a[i][1]+a[i][2]*a[i][2];
            c<d?c=d:1;
        }
        for(i=0;i<n;i++)
        {
            if(l[i]*l[i]<=c)
            p++;
        }
        printf("%d\n",p);
    }
    return 0;
}
