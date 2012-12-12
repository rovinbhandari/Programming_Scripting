#include<iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;
int main()
{
    int t,socks[256],ch;
    scanf("%d%c",&t);
    while(t--)
    {
        ch=0;
        memset(socks,0,sizeof(socks));
        while(!(ch=='R'||ch=='G'||ch=='B'||ch=='W'))
        {
            ch=getchar();
        }
        while(ch=='R'||ch=='G'||ch=='B'||ch=='W')
        {
            socks[ch]++;
            ch=getchar();
        }
        if(socks['R']&1||socks['B']&1||socks['W']&1||socks['G']&1)
        {
            printf("NO\n");
        }
        else
        printf("YES\n");
    }
    return 0;
}
