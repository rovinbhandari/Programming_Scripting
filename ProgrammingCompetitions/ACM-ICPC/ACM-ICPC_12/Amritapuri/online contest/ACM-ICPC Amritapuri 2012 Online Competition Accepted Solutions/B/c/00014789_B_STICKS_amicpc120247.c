#include<stdio.h>

int main()
{
    char ch;
    int t, test;
    double max, ans1, ans2;
    long int count, N, M, i, j, A[50000], B[50000], C[50000], L[50000];
    scanf("%d", &t);
    for (test=0; test<t; test++)
    {
        scanf("%ld%ld", &N, &M);
        for(i=0; i<N; i++)
        {
            scanf("%ld", &L[i]);
        }
        max=0;
        for(i=0; i<M; i++)
        {
            scanf("%ld", &A[i]);
            scanf("%ld", &B[i]);
            scanf("%ld", &C[i]);
            ans1=(A[i]*A[i]+B[i]*B[i]);
            ans2=ans1+(C[i]*C[i]);
            if(max<ans2)
                max=ans2;
        }
        count=0;
        for(i=0;i<N;i++)
        {
            if((L[i]*L[i])<=max)
                count++;
        }
        printf("%ld\n", count);
        if(test<t-1)
            scanf("%c", &ch);
    }
    return 0;
}
