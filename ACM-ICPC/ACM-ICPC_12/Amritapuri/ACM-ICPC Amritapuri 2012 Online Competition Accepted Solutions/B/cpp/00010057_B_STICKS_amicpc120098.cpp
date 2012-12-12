#include <cstdio>
#include <cmath>
int main(int argc, const char *argv[])
{
    long long int t,n,m;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        scanf("%lld", &m);
        long double max = 0.0;
        long long int lengths[n],a,b,c,i;
        for (i=0; i<n;i++)
            scanf("%lld", &lengths[i]);
        for (i=0; i<m; i++)
        {
            scanf("%lld%lld%lld",&a,&b,&c);
            long long int l = a*a + b*b + c*c;
            if (max < l)
                max = l;
        }
        max = sqrt(max);
        long long int count = 0;
        for (i =0; i<n;i++)
            if (lengths[i] <= max)
                count++;
        printf("%lld\n",count);
    }
    return 0;
}
