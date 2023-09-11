#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int T;
    cin>>T;
    char socks[51];
    int R,G,B,W;
    for (int i = 0; i < T; i++)
    {
        cin>>socks;
        R=0; G=0; B=0; W=0;
        int length = strlen(socks);
        for (int j = 0; j < length; j++)
        {
            if (socks[j] == 'R')
            {
                R++;
            }
            else if (socks[j] == 'G')
            {
                G++;
            }
            else if (socks[j] == 'B')
            {
                B++;
            }
            else
            {
                W++;
            }
        }

        if ((R%2 == 0) && (G%2 == 0) && (B%2 == 0) && (W%2 == 0))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }

    }
    return 0;
}
