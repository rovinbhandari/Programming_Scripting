#include <iostream>
#include <string>
using namespace std;

int main ()
{
        int t;
        cin >> t;
        string s;
        int i, l, flag;
        while (t--) {
        int a[4] = {0};
        flag = 0;
                cin >> s;
                l = s.size();
                for (i = 0; i < l; i++ ) {
                        if (s[i] == 'R' ) {
                                a[0]++;
                        } else if(s[i] == 'G') {
                                a[1]++;
                        } else if (s[i] == 'B') {
                                a[2]++;
                        } else if (s[i] == 'W') {
                                a[3]++;
                        }
                }
                for (i =0 ; i < 4; i++) {
                        if( a[i] % 2 != 0) {
                                flag = 1;
                                break;
                        }
                }
                if (flag == 0 ) {
                        cout << "YES\n";
                } else cout << "NO\n";
        }
        return 0;
}
