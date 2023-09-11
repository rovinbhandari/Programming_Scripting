#include<stdio.h>

int main()
{
    int i,t;
    char ch[100];
    int r,g,b,w;
    scanf("%d",&t);
    while(t--)
    {
        r=b=g=w=0;
        scanf("%s",ch);
        for(i=0;i<strlen(ch);i++)
        {
            if(ch[i]=='R')
                r++;
            else if(ch[i]=='G')
                g++;
            else if(ch[i]=='B')
                b++;
            else if(ch[i]=='W')
                w++;
        }
        if((r%2==0) &&(g%2==0) &&(b%2==0) &&(w%2==0))
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
