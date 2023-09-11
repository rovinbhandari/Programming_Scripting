#include<stdio.h>
#include<stdlib.h>
//#include<math.h>

int main(void)
{
    int test=0;
    long int N,M,L[50100]={0},i,j,k,count=0;
    long int A[50100]={0},B[50100]={0},C[50100]={0};
    long long int max=0,value=0;
    scanf("%d",&test);
    for(k=0;k<test;k++)
    {
        count=0;max=0;
        scanf("%ld %ld",&N,&M);
        for(i=0;i<N;i++)scanf("%ld",L+i);
        for(j=0;j<M;j++)
        {
            scanf("%ld %ld %ld",&A[j],&B[j],&C[j]);
            value=A[j]*A[j] + B[j]*B[j] + C[j]*C[j];
            //value=sqrt(value);
            if(value>max)max=value;
        }
        for(i=0;i<N;i++)
        {
            if((L[i]*L[i])<=max)count++;
        }
        printf("%ld\n",count);
    }
    return 0;
}
