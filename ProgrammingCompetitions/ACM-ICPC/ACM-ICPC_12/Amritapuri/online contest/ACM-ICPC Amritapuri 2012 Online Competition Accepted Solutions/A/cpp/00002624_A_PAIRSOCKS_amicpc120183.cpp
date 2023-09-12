#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string s;
        cin>>s;
        int r=0,g=0,b=0,w=0,i=0;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='R')r++;
            else if(s[i]=='B')b++;
            else if(s[i]=='G')g++;
            else if(s[i]=='W')w++;
        }
        if((r%2!=0)||(g%2!=0)||(w%2!=0)||(b%2!=0))
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
