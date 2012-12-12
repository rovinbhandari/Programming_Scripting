#include<stdio.h>
#include<cstdlib>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    int  test_cases;
    scanf("%d",&test_cases);
    int sol[test_cases];
    //char s[51];
    string s;
    int len;
    int r,g,b,w;
    for(int i=0;i<test_cases;i++)
    {
        r=g=b=w=0;
        //scanf("%s",s);
        cin>>s;
        //len = strlen(s);
        len  =s.length();
        for(int j=0;j<len;j++)
        {
            if(s[j]=='R')
            {
                r++;
            }
            if(s[j]=='G')
                g++;
            if(s[j]=='B')
                b++;
            if(s[j]=='W')
                w++;
        }
        if(r%2==0 && b%2==0 && g%2==0 && w%2==0)
        {
            sol[i]=1;
        }
        else
            sol[i] = -1;
    }
    for(int i=0;i<test_cases;i++)
    {
        if(sol[i]==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
