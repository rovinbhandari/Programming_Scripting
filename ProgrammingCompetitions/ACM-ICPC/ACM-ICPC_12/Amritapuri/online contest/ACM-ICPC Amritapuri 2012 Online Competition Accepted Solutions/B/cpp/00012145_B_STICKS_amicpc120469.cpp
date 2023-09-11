#include<stdio.h>
#include<math.h>
main()
{
      unsigned long long int t,n,m,a,b;
      scanf("%llu",&t);
      for(a=1;a<=t;a++)
      {
                       scanf("%llu %llu",&m,&n);
                       unsigned long long int s[m];
                       for(b=1;b<=m;b++)
                       scanf("%llu",&s[b-1]);
                       unsigned long long int len,bre,hei,sqrt,k=0,ans=0;
                       for(b=1;b<=n;b++)
                       {
                                        scanf("%llu %llu %llu",&len,&bre,&hei);
                                        sqrt=(unsigned long long int)pow((len*len+bre*bre+hei*hei),0.5);
                                        if(sqrt>=k)
                                        k=sqrt;
                       }
                       for(b=0;b<m;b++)
                       {
                                       if(s[b]<=k)
                                       ans++;
                       }
                       printf("%llu\n",ans);
      }
      return 0;
}
