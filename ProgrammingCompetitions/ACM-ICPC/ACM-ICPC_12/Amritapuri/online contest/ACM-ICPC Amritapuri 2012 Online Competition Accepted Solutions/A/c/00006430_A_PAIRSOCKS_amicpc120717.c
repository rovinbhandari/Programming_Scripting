#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    char s[51];
    scanf("%s",&s);
    int r=0,g=0,b=0,w=0;
    int i,len;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='R')
        r++;
        else if(s[i]=='G')
        g++;
        else if(s[i]=='B')
        b++;
        else if(s[i]=='W')
        w++;
    }
    if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
    printf("YES\n");
    else
    printf("NO\n");
    }
    return 0;
}
