#include <iostream>
#include <map>
#include <cstdio>
 
using namespace std;
 
int main()
{
    int t, flag;
    string s;
 
    scanf("%d", &t);
 
    while (t--) {
        map<char, int>m;
        map<char, int>::iterator it;
        cin >> s;
 
        flag = 0;
 
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        for (it = m.begin(); it != m.end(); it++) {
            if ((*it).second % 2 != 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            cout << "YES" <<endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
