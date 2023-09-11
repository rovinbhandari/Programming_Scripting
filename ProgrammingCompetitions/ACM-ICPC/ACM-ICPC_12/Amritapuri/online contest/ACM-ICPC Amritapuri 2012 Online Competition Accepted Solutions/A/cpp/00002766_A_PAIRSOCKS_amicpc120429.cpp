#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
    int t;
    char s[52];
    int r,g,b,w;
    scanf("%d",&t);
    while(t--)
    {
        r=g=b=w=0;
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='R')
            {
                if(r==0)r++;
                else if(r==1)r--;
            }
            else if(s[i]=='G')
            {
                if(g==0)g++;
                else if(g==1)g--;
            }
            else if(s[i]=='B')
            {
                if(b==0)b++;
                else if(b==1)b--;
            }
            else if(s[i]=='W')
            {
                if(w==0)w++;
                else if(w==1)w--;
            }
        }
        if(r==0 && g==0 && b==0 && w==0)
        printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
