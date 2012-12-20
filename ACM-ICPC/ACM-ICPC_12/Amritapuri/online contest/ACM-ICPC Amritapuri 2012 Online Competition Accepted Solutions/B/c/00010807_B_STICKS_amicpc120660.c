#include<stdio.h>

#define TOLERANCE 0.0001

double myabs(const double x){
  if (x > 0.0)
    return x;
  return -x;
}

double mysqrt(const double x){
  double assumption = 1.0;
  if (x < 0.0)
    return 0.0;
  while (myabs(assumption * assumption - x) > TOLERANCE){
    assumption = 0.5 * (assumption + x / assumption);
  }
  return assumption;
}

int main()
{
    int p,n,m,i,j;
     double d,max=0,p1,p2,p3;
     int flag=0;
    long l[100000];
        long k[100000][3];
    scanf("%d",&p);
    while(p--)
    {
        scanf("%d %d",&n,&m);
         flag=0;
         max=0;
        for(i=0;i<n;i++)
        scanf("%ld",&l[i]);
        for(i=0;i<m;i++)
        {
            scanf("%ld%ld%ld",&k[i][0],&k[i][1],&k[i][2]);
            p1=k[i][0]*k[i][0];
            p2=k[i][1]*k[i][1];
            p3=k[i][2]*k[i][2];
            d=mysqrt(p1+p2+p3);
            if(d>max)
            max=d;
        }
        for(i=0;i<n;i++)
        {
            if(l[i]<=max)
            flag++;
        }
        printf("%d\n",flag);

    }
    return 0;
}
