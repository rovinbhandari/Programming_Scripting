#include <stdio.h>
#include <math.h>
int main()
{
    int T,count;
    long L[50000],MAX_L;
    long long MAX,t;
    unsigned int M[50000][3],a,b,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%u %u",&a,&b);
        i=0;
        while(i<a)
        {
            scanf("%ld",&L[i]);
            i++;
        }
        i=0;
        MAX=0,MAX_L=0;
        while(i<b)
        {
            scanf("%u %u %u",&M[i][0],&M[i][1],&M[i][2]);
            t=pow(M[i][0]*M[i][0]+M[i][1]*M[i][1]+M[i][2]*M[i][2],0.5);
            if(MAX<=t)
                MAX=t;
            if(MAX_L<M[i][0])
                MAX_L=M[i][0];
            if(MAX_L<M[i][1])
                MAX_L=M[i][1];
            if(MAX_L<M[i][2])
                MAX_L=M[i][2];
            i++;
        }
        count=0;
        for(i=0;i<a;i++)
        {
            if(L[i]<=MAX_L||L[i]<=MAX)
                count++;
        }
        printf("%d\n",count);
        if(T!=0)
            getchar();
    }
    return 0;
}
