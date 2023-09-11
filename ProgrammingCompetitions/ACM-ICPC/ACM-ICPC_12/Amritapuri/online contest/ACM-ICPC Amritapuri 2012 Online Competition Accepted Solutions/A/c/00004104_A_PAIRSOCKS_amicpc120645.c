
#include<stdio.h>
#include<string.h>
int main()
{
    int i,t,n,len,cR,cW,cG,cB;
    char str[51];
    scanf("%d",&t);
    while(t--)
    {
        len=0;
        cR=0;
        cB=0;
        cW=0;
        cG=0;
        scanf("%s",str);
        len=strlen(str);
        for(i=0;i<len;++i)
        {
            if(str[i]=='R')
                cR++;
            if(str[i]=='W')
                cW++;
            if(str[i]=='G')
                cG++;
            if(str[i]=='B')
                cB++;
        }
        if(cR%2==0 && cW%2==0 && cB%2==0 && cG%2==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
