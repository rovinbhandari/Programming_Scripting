#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
main()
{
    int te;
    scanf("%d",&te);
    while(te--)
    {
        int r=0,g=0,b=0,w=0;
        char s[55];
        cin>>s;
        int n=strlen(s);
        for(int i=0;i<n;i++)
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
        if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
            printf("YES\n");
        else
            printf("NO\n");
        }
}
