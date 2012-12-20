#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        char c[55];
        cin >> c;
        int r=0,g=0,b=0,w=0;
        for(int i = 0 ; c[i] ; i++)
            switch(c[i])
            {
                case 'R':r++;break;
                case 'G':g++;break;
                case 'B':b++;break;
                case 'W':w++;break;
            }
        if((r%2 != 0) || (b%2 != 0) || (g%2 != 0) || (w%2 != 0))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
