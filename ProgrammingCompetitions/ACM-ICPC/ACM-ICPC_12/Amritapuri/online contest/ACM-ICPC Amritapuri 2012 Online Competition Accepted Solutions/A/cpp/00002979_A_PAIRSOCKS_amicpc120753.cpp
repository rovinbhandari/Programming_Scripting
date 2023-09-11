#include<string.h>
#include<stdio.h>
main()
{
      int a,b,d,e;
      char c[51];
      int f[4];
      scanf("%d",&a);
      for(b=1;b<=a;b++)
      {
                       scanf("%s",c);
                       d=strlen(c);
                       f[0]=0;
                       f[1]=0;
                       f[2]=0;
                       f[3]=0;
                       for(e=0;e<d;e++)
                       {
                                       if(c[e]=='R')
                                       f[0]++;
                                       else if(c[e]=='G')
                                       f[1]++;
                                       else if(c[e]=='B')
                                       f[2]++;
                                       else
                                       f[3]++;
                       }
                       if(f[0]%2==0 && f[1]%2==0 && f[2]%2==0 && f[3]%2==0)
                       printf("YES\n");
                       else
                       printf("NO\n");
      }
      return 0;
}
                                       
                                             
