#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int L[50000],a[50000],b[50000],c[50000];
    long long int N,M,t,max,count,i,j;

    scanf("%lld",&t);

    while(t--)
    {
        max = 0;
        count = 0;

        scanf("%lld %lld",&N,&M);

        for(i=0;i<N;i++)
        {
            scanf("%lld",&L[i]);
            L[i] = L[i]*L[i];
        }

        for(j=0;j<M;j++)
        {
            scanf("%lld %lld %lld",&a[j],&b[j],&c[j]);
            if(max < a[j]*a[j] + b[j]*b[j] + c[j]*c[j])
            {
                max = a[j]*a[j] + b[j]*b[j] + c[j]*c[j];
            }
        }

        for(i=0;i<N;i++)
        {
            if(L[i]<=max)
               count++;
        }

        printf("%lld\n",count);
    }
  return 0;
}
