#include <stdio.h>
#include <string.h>

int main()
{
       int i, j, k, T;
       int cr, cg, cb, cw;
       char inp[60];

       scanf("%d", &T);
       while(T--)
       {
               cr=cg=cb=cw = 0;
               scanf("%s", &inp);
               k = strlen(inp);
               for(i=0;i<k;i++)
               {
                       if(inp[i]=='R')
                               cr++;
                       else if(inp[i]=='W')
                               cw++;
                       else if(inp[i]=='G')
                               cg++;
                       else if(inp[i]=='B')
                               cb++;
               }
               if(cg%2==0 and cw%2==0 and cb%2==0 and cr%2==0)
                       printf("YES\n");
               else
                       printf("NO\n");
       }
       return 0;
}
