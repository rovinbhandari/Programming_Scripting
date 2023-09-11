#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int t, i, j;
    cin >> t;
    string s;
    map <char, int> m;
    for(i = 0; i < t; i++){
          cin >> s;
          for(j = 0; j < s.size(); j++){
                      m[s[j]]++;
          }
          if(m['R']%2 == 0 && m['G']%2 == 0 && m['B']%2 == 0 && m['W']%2 == 0)
                      cout << "YES" << endl;
          else
               cout << "NO" << endl;
          m.clear();
    }
    
    //system("pause");
    return 0;
}
