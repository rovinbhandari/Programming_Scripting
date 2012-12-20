#include<stdio.h>
#include<string.h>


int main()
 {
 int t,r,g,b,w;
 char c;
scanf("%d",&t);
c=getchar();
 while(t--)
{ r=g=b=w=0;
c=getchar();
while(c!='\n')
{
              if(c=='R') r++;
              else if(c=='G') g++;
              else if(c=='B') b++;
              else w++;
              c=getchar();
              }
              if(r&1 || g&1 || b&1 || w&1)
              printf("NO\n");
              else printf("YES\n");

}
     return 0;
     }
