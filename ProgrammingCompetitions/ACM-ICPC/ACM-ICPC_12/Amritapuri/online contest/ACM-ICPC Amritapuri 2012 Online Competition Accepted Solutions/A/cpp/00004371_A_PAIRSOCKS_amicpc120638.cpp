#include<stdio.h>
int main()
{
    int t,i;
    char ans[1001][10];i=0;
    scanf("%d",&t);
    while(t--)
    {int r,g,w,b;r=g=w=b=0;int k=0;char s[2000];
   // printf("4");
         fflush(stdin);
         scanf("%s",s);
              while(s[k]!='\0'){
              
              
              char ch=s[k];
              if(ch=='R')
              r++;
              else if(ch=='G')
              g++;
              else if(ch=='W')
              w++;
              else if(ch=='B')
              b++;
              k++;
              }
              if(r%2==0 && g%2==0 && w%2==0 && b%2==0)
                        sprintf(ans[i],"YES\n");
              else
                        sprintf(ans[i],"NO\n");
              i++;
    }
    for(t=0;t<i;t++)
                    printf("%s",ans[t]);
   
    return 0;
}
