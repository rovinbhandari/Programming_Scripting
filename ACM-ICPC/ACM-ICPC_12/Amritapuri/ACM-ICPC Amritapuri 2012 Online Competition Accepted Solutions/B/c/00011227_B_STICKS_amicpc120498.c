#include<stdio.h>
#define N_max 50000
#define M_max 100000

int main()
{
    int t;
    long L[N_max],A[M_max],B[M_max],C[M_max],out[M_max];
    long m,n,i,j,d,max=0,count=0;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        max=0,count=0;
        scanf("%ld %ld",&n,&m);
        for(j=0;j<n;j++)
        {
            scanf("%ld",&L[j]);
        }
        for(j=0;j<m;j++)
        {
            scanf("%ld %ld %ld",&A[j],&B[j],&C[j]);
            d=A[j]*A[j]+B[j]*B[j]+C[j]*C[j];
            if(max<d)
            {
                max=d;
            }
        }
        for(j=0;j<n;j++)
        {
            if((L[j]*L[j])<=max)
            {
                count++;
            }
        }
        out[i]=count;
    }
    for(i=0;i<t;i++)
    {
        printf("%ld\n",out[i]);
    }
    return 0;
}
