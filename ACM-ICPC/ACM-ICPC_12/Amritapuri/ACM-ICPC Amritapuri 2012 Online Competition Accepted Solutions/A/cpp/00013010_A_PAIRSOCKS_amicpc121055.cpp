#include<stdio.h>
#include<string.h>

main()
{
      int t,i,j,n;
      scanf("%d",&t);
      int r,g,b,w;
      char c[50];
      if(t>=1&&t<=1000)
      {
         for(i=0;i<t;i++)
         {
           r=b=g=w=0;
           scanf("%s",c);
           n = strlen(c);
           for(j=0;j<n;j++)
              {  
                 if(c[j] == 'R'){ r++; }
                 else if(c[j]=='G'){g++; }
                 else if(c[j]=='B'){b++; }
                 else if(c[j]=='W'){w++; }
            }
              if(r%2==0 && w%2 == 0 && g%2==0 && b%2==0)
                 printf("YES\n");
              else
                 printf("NO\n");
          }
      }
      
}
