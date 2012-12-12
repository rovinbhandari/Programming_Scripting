#include <iostream>
#include <string>
using namespace std;


int main()
{
    long long int t;
    long long int r = 0,g = 0,b = 0,w = 0;
    cin >> t;
    while(t--) {
    string s;
    cin >> s;
	r = 0; g = 0; b = 0; w = 0;
    for (long long int i = 0;i < s.size(); i++) {
        if ( s[i] == 'R') r++;
        if ( s[i] == 'W') w++;
        if ( s[i] == 'G') g++;
        if ( s[i] == 'B') b++;
                
    }
    if ( (r%2 == 0) && (w%2 == 0) && (g%2 == 0) && (b%2 == 0) )cout << "YES" << endl;
    else  
    cout << "NO" << endl;
    }
    return 0;
}

