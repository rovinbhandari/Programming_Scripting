#include <stdio.h>
#include <math.h>
int main()
{

    long int T,M,N,i,a[50005],l,b,h,count;
    double temp,max;
    scanf("%ld",&T);
    while(T--)
    {
         max=-1;count=0;
        scanf("%ld%ld",&N,&M);
        for(i=0;i<N;i++)
        {
            scanf("%ld",&a[i]);
        }
        for(i=0;i<M;i++)
        {
            scanf("%ld%ld%ld",&l,&b,&h);
            temp= l*l+b*b+h*h;
            temp=sqrt(temp);
            if(temp>max)
             max=temp;
        }
       // printf("%f\n",max);
        for(i=0;i<N;i++)
        {
            if(a[i]<=max)
              count++;
        }
        printf("%ld\n",count);

    }
    return 0;
}
