#include <iostream>
#include<string.h>

using namespace std;

int main()
{
    int t,r,g,b,w;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        r=g=b=w=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='R')
            ++r;
            else if(s[i]=='G')
            ++g;
            else if(s[i]=='B')
            ++b;
            else if(s[i]=='W')
            ++w;
        }
if ((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
cout<<"YES\n";
else
cout<<"NO\n";
    }

    return 0;
}
