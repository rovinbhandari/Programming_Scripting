#include<stdio.h>
#include<math.h>
int main()
{
    int t,n,m,count,max,i;
    double x,y,z;
    int l[50000],d[50000];
    scanf("%d",&t);
    while(t--)
    {
              count=0;
              max=0;
              scanf("%d %d",&n,&m);
              for(i=0;i<n;i++)
              scanf("%d",&l[i]);
              for(i=0;i<m;i++)
              {
                              scanf("%lf %lf %lf",&x,&y,&z);
                              d[i]=(int)sqrt((x*x) + (y*y) + (z*z));
                              if(d[i]>max)
                              max=d[i];
              }
              for(i=0;i<n;i++)
              {
                              if(l[i]<=max)
                              count++;
              }
              printf("%d\n",count);
    }
    return 0;
}
