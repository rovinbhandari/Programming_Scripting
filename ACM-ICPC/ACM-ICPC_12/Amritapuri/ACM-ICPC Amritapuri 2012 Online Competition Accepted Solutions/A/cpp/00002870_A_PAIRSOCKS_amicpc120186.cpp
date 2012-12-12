#include<iostream>
#include<string>
using namespace std;
int main()
{

    int tc;
    cin>>tc;
    string str;
    while(tc--)
    {
        cin>>str;
        int R=0,G=0,B=0,W=0;
        for(int i=0;i<str.length();i++)
        {
           if(str[i]=='R')
            R++;

            if(str[i]=='G')
            G++;

            if(str[i]=='B')
            B++;

            if(str[i]=='W')
            W++;
        }
        if(R%2 == 0 && G%2==0 && B%2 == 0 && W%2 == 0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
