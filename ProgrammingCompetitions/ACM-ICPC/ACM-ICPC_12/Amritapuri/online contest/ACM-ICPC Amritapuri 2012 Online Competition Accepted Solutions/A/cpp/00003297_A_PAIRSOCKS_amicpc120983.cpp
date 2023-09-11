#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int r=0,b=0,g=0,w=0;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]=='W')
                w++;
            if(s[j]=='B')
                b++;
            if(s[j]=='R')
                r++;
            if(s[j]=='G')
                g++;
        }
        if(r%2==0 && b%2==0 && g%2==0 && w%2==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
