#include <iostream>
#include <string>
//#include <math.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int m=0;m<t;m++)
    {
        int r=0,g=0,b=0,w=0;
        string s;
        cin>>s;
        int n= s.length();
        for(int i=0;i<n;i++)
        {
            switch(s[i])
            {
                case 'R':r++;break;
                case 'G':g++;break;
                case 'B':b++;break;
                case 'W':w++;break;
            }

        }
        if( (r%2)==0 && (g%2)==0 && (b%2)==0 && (w%2)==0)
        cout<<"YES\n";
        else
        cout<<"NO\n";

    }
    return 0;
}
