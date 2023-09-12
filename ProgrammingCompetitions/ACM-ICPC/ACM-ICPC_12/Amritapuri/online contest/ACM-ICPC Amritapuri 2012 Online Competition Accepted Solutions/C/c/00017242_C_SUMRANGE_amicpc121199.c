#include <stdio.h>
int func(long a[],int N,long L,long H);
int main()
{
    int T,N,i,count,j,k;
    long L,H,x,sum,a[1000];

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %ld %ld",&N,&L,&H);
        for(i=0;i<N;i++)
        {
            scanf("%ld",&x);
            a[i]=x;
        }
        printf("%d\n",func(a,N,L,H));
    }
    return 0;
}
int func(long a[],int n,long L,long H)
{
   int c, d,count=0,i,j,k;

    long sum,t;
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (a[d] > a[d+1])
      {
        /* Swapping */

        t         = a[d];
        a[d]   = a[d+1];
        a[d+1] = t;
      }
    }
  }
   for (i=0; a[i]<H-1; i++) {
                    //if (a[i] > H) continue;
                    for (j=i+1; a[i]+a[j]<H; j++) {
                         for (k=j+1; a[i]+a[j]+a[k]<=H; k++) {
                            sum = a[i]+ a[j]+ a[k];
                            if (L <= sum) count++;
                        }
                    }
        }
return count;
}


