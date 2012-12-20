#include<stdio.h>
#include<string.h>
#include<string>
#define s(a)(scanf("%d",&(a)))
#define p(a)(printf("%d\n",(a)))
#include<iostream>

using namespace std;

int main()
{
    string s;
    int r,b,g,w;
    int a;
    s(a);
    for(int i=0;i<a;i++)
    {
        r=0,b=0,g=0,w=0;
        cin>>s;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]=='W')
                   w++;
            if(s[j]=='B')
            b++;
            if(s[j]=='G')
            g++;
            if(s[j]=='R')
            r++;

        }
        if((w%2==0)&&(b%2==0)&&(g%2==0)&&(r%2==0))
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }

}
