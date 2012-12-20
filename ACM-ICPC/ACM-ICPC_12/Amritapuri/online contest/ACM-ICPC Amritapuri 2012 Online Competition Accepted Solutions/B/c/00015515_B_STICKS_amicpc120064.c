#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

int main()
{
    int test=0;
    scanf("%d",&test);
    int i=0;
    for(i=0;i<test;i++)
    {
        int N=0,M=0;
        scanf("%d%d",&N,&M);
        long long int *arr;
        int j=0;
        arr=(long long int *)malloc(sizeof(long long int)*N);
        for(j=0;j<N;j++)
            scanf("%lld",&arr[j]);

        long long int max=-1;
        long long int dig=0;
        int count=0;
        long long int a=0,b=0,c=0;
        for(j=0;j<M;j++)
        {
            scanf("%lld%lld%lld",&a,&b,&c);
            dig = a*a + b*b + c*c;
//            printf("dig %lld\n",dig);
            if(max<dig)
                max=dig;
        }       
        for(j=0;j<N;j++)
        {
            long long int temp=arr[j]*arr[j];
//            printf("%lld\n",temp);
            if(max>=temp)
                count++;
        }
        printf("%d\n",count);
        free(arr);
    }

    return 0;
}
