#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
int n,t,test,r,g,b,w,i;
char s[10004];
scanf("%d",&t);
for(test=0;test<t;test++)
  {  r=g=b=w=0;
      scanf("%s",s);
       n=strlen(s);
        for(i=0;i<n;i++)
	 {if(s[i]=='R')r++;
          if(s[i]=='G')g++;
          if(s[i]=='B')b++;
	  if(s[i]=='W')w++;
  
         }
          if(r==0&&g==0&&b==0&& w==0)
           {printf("NO\n");
           }
          else
           if(r%2==0&&g%2==0&&b%2==0&& w%2==0)
          {
          printf("YES\n");
          }
         else
           printf("NO\n");
	      
  }

}
