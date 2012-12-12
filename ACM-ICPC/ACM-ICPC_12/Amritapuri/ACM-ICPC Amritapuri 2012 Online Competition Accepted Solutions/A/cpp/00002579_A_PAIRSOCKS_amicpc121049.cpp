#include <iostream>

using namespace std;

int main(void)
{
    int T, i, rcnt, gcnt, bcnt, wcnt;
    string s;

    cin >> T;
    while(T--)
    {
        cin >> s;
        rcnt = gcnt = bcnt = wcnt = 0;
        for(i = 0; i < s.length(); i++)
        {
            switch(s[i])
            {
            case 'R':
                rcnt++;
                break;
            case 'G':
                gcnt++;
                break;
            case 'B':
                bcnt++;
                break;
            case 'W':
                wcnt++;
                break;
            }
        }

        if(rcnt % 2 == 0 && gcnt % 2 == 0 && bcnt % 2 == 0 && wcnt % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
