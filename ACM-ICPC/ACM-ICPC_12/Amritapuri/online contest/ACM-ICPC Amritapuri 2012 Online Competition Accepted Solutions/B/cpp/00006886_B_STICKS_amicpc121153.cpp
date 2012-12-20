#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    int arr[50001];
    int n,m;
    long long int a,b,c,x,y;
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            {
                scanf("%d",&arr[i]);
            }
        long long int max = 0;
        for(int j=0;j<m;j++)
            {
                scanf("%lld %lld %lld",&a,&b,&c);
                x = a*a+b*b+c*c;
                y = sqrt(x);
                if(y>max)
                    max = y;
            }
        int count=0;
        for(int k=0;k<n;k++)
            {
                if(arr[k]<=max)
                    count++;
            }
        printf("%d\n",count);
    }
    return 0;
}
