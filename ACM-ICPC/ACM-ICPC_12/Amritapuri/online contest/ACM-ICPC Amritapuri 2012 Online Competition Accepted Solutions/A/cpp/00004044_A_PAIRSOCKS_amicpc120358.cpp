#include<stdio.h>
#include<string.h>

int t,r,g,b,w;
char s[51];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        r=g=b=w=0;
        getchar();
        scanf("%s",s);
        int len;
        len=(int)strlen(s);
        int i=0;
        for(i=0;i<len;i++)
        {
            if(s[i]=='R')
            {
                r++;
            }
            else if(s[i]=='G')
            {
                g++;
            }
            else if(s[i]=='W')
            {
                w++;
            }
            else if(s[i]=='B')
            {
                b++;
            }

        }
        if(r%2==0&&b%2==0&&g%2==0&&w%2==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }


    }


    return 0;
}
