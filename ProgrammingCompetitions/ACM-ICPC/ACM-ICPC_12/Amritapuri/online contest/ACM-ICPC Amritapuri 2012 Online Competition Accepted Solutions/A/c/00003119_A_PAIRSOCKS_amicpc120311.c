#include<stdio.h>
#include<stdlib.h>
int main()
{
    char st[100];
    int t,r,w,b,g,i;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%s",st);
              r=b=g=w=0;
              for(i=0;st[i]!='\0';i++)
              {
                                      if(st[i]=='R')
                                                    r++;
                                      else if(st[i]=='B')
                                           b++;
                                      else if(st[i]=='G')
                                           g++;
                                      else
                                          w++;
              }
              if(r%2==0 && g%2==0 && w%2==0 && b%2==0)
                        printf("YES\n");
              else
                  printf("NO\n");
    }
    return 0;
}
