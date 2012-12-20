#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;    
        cin >> s;

        int freq[26];
        memset(freq, 0, sizeof(freq));

        for (int i = 0; i < s.length(); ++i)
        {
            freq[s[i]-'A']++;
        }

        bool found = true;
        for (int i = 0; i < 26; ++i)
        {
            if ((freq[i]%2) != 0) found = false;
        }

        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}