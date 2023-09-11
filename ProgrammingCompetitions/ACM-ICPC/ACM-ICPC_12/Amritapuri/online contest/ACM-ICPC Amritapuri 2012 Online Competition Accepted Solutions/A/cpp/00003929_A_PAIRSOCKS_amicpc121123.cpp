#include<iostream>
#include<string>

using namespace std;


int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string c;
        int R=0, G=0, B=0, W=0;
        cin>>c;
        for(int j=0;j<c.length();j++)
        {
            if(c[j] == 'R')
            R++;
            else if(c[j] == 'G')
            G++;
            else if(c[j] == 'B')
            B++;
            else if(c[j] == 'W')
            W++;
        }
        if(R%2!=0 || G%2!=0 || B%2!=0 ||W%2!=0)
        cout<<"NO\n";
        else
        cout<<"YES\n";
    }
    return 0;
}
