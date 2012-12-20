#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string s;
        int r=0,g=0,b=0,w=0;
        cin>>s;
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='R')r++;
            if(s[i]=='G')g++;
            if(s[i]=='B')b++;
            if(s[i]=='W')w++;
        }
        if(!(r%2 || g%2 || w%2 || b%2))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

