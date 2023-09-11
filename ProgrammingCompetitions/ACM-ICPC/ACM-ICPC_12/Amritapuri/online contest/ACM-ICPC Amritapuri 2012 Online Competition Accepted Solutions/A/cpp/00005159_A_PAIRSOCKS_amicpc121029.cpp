#include<stdio.h>
main()
{
      int t,i;
      bool r,g,b,w;
      char s[51];
      scanf("%d",&t);
      while(t--)
      {
               scanf("%s",s); 
               i=0;
               r=g=b=w=true;
               for(;s[i];i++)
               {
                     if(s[i]=='R')r=!r;
                     else if  (s[i]=='G')g=!g; 
                     else if  (s[i]=='B')b=!b; 
                     else w=!w; 
                         
               }
               if(r&&g&&b&&w)printf("YES\n");
               else printf("NO\n");
      }
      return 0;
}
