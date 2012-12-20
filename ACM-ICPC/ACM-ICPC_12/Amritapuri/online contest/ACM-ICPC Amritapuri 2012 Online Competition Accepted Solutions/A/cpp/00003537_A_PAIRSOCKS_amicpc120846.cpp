#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int t;

    char a[100];
    cin>>t;
    while(t--)
    {
        int r=0,g=0,b=0,w=0;

        cin>>a;
        for(int i=0; i<strlen(a); i++)
        {
            if(a[i]=='R')
                r++;
            else if(a[i]=='G')
                g++;
            else if(a[i]=='B')
                b++;
            else
                w++;
        }
        if(r%2!=0||g%2!=0||b%2!=0||w%2!=0)
            cout<<"NO\n";
        else
            cout<<"YES\n";

    }
}
