#include<stdio.h>
#include<string.h>
int main()
{
    int i,n,a;
    scanf("%d",&n);
    int arr[1000];
    for(i=0;i<n;i++)
    {
    char socks[50];
    scanf("%s",socks);
    if(strlen(socks)%2!=0)
    {
               arr[i]=0;           
    }
    else
    {
        int flagr=0,flagg=0,flagw=0,flagb=0;
        for(a=0;a<strlen(socks);a++)
        {
                if(socks[a]=='R')
                flagr++;
        }
        for(a=0;a<strlen(socks);a++)
        {
                if(socks[a]=='G')
                flagg++;
        }
        for(a=0;a<strlen(socks);a++)
        {
                if(socks[a]=='W')
                flagw++;
        }
        for(a=0;a<strlen(socks);a++)
        {
                if(socks[a]=='B')
                flagb++;
        }
        if(((flagr%2)==0)&&((flagg%2)==0)&&((flagw%2)==0)&&((flagb%2)==0))
        {
                        arr[i]=1;
        }
        else
        arr[i]=0;
    }
}
for(i=0;i<n;i++)
{
                if(arr[i]!=0)
                printf("YES\r\n");
                else
                printf("NO\r\n");
}
return 0;
}
