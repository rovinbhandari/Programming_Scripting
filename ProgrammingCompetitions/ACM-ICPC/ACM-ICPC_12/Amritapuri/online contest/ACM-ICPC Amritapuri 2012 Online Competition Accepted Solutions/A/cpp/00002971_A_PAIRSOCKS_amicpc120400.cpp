#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    int i,j,k,m,n,t;
    string s,y;
    scanf("%d",&t);
    while(t--)
    {
        y="";
        int a[4]={0};
        cin>>s;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='R')
            a[0]++;
            else if(s[i]=='G')
            a[1]++;
            else if(s[i]=='B')
            a[2]++;
            else
            a[3]++;
        }
        for(i=0;i<4;i++)
        {
            if(a[i]%2!=0)
                y="NO";
        }
        if(y=="")y="YES";
        cout<<y<<"\n";
    }
    return 0;
}
