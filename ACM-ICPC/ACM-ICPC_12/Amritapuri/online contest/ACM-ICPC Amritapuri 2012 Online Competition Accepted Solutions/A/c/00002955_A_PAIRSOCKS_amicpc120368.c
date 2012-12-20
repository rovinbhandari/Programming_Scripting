#include<stdio.h>

int main()
{
    int i,t,n,r,g,b,w;
    char str[51];
    scanf("%d\n",&t);

    while(t--)
    {
              r=g=b=w=i=0;
              gets(str);
              while(str[i]!='\0')
              {
                              if(str[i]=='R')
                              r++;
                              if(str[i]=='G')
                              g++;
                              if(str[i]=='B')
                              b++;
                              if(str[i]=='W')
                              w++;
               i++;
              }
              if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
              printf("YES\n");
              else
              printf("NO\n");
    }
    //getchar();
    return 0;
}
