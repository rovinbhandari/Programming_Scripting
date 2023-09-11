#include<iostream>
#include<string>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int r=0, g=0, b=0, w=0;
        for(int i=0;i<s.size();i++) {
            if(s[i] == 'R') r++;
            if(s[i] == 'G') g++;
            if(s[i] == 'B') b++;
            if(s[i] == 'W') w++;
        }
        if(r%2==0 && b%2==0 && g%2==0 && w%2==0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}