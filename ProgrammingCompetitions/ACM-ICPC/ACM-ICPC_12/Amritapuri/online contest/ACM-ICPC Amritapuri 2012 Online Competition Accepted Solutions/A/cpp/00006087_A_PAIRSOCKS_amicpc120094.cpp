#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,i;
    bool r,g,b,w;
    char str[51];
    scanf("%d",&t);
    while(t--)
    {
              r=g=b=w=true;
              scanf("%s",str);
              for(i=0;i<strlen(str);i++)
              {
                                        if(str[i]=='R')
                                        r=(r==true)?false:true;
                                        if(str[i]=='G')
                                        g=(g==true)?false:true;
                                        if(str[i]=='B')
                                        b=(b==true)?false:true;
                                        if(str[i]=='W')
                                        w=(w==true)?false:true;
              }

              if(r==true && g==true && b==true && w==true)
                         printf("YES\n");
                         else
                         printf("NO\n");
    }
    return 0;
}
