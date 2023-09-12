#include<stdio.h>
int main()
{
    char s[51];
    int t,lr=0,lb=0,lg=0,lw=0,i;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%s",s);
              lr=lg=lw=lb=0;
              for(i=0;s[i]!='\0';i++)
              {
                                     if(s[i]=='R')
                                     lr++;
                                     else if(s[i]=='G')
                                     lg++;
                                     else if(s[i]=='B')
                                     lb++;
                                     else if(s[i]=='W')
                                     lw++;
                                     }
              if(lr%2==0 && lw%2==0 && lg%2==0 && lb%2==0 ) 
              printf("YES\n");
              else 
              printf("NO\n");
              }
   
    }
    
