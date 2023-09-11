#include<stdio.h>
//#include<math.h>

int main()
{
    int cas;
    int nos,nob,i,j,count;
    long long int l,b,h;
    long long int max,dia;
    long long int arr[100001];
        scanf("%d",&cas);
    while(cas--)
    {
      count=0;
      scanf("%d %d",&nos,&nob);
      for(i=0;i<nos;i++)
      {
        scanf("%d",&arr[i]);
      }
      max=0;
      for(i=0;i<nob;i++)
      {
         scanf("%lld %lld %lld",&l,&b,&h);
         dia=((l*l)+(b*b)+(h*h));
         if(dia>max)
           max=dia;
      }
    for(i=0;i<nos;i++)
    {
                      if(arr[i]*arr[i]<=max)
                        count++;
    }
    printf("%d\n",count);
}
    return 0;
}
