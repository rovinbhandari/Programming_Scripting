#include <iostream>
#include <cstdio>
#include <string>
#include <map>
 
using namespace std;
 
int main()
{
    int n,i;
    string s;
        
    scanf("%d", &n);
    
    while ( n-- ) {
          cin >> s;
          map <char,int> m;
          
          for ( i = 0; i < s.size(); i++ ) {
              m[s[i]]++;
          }
          
          if ( m['R']%2 == 0 && m['G']%2 == 0 && m['W']%2 == 0 && m['B']%2 == 0 ) printf("YES\n");
          else printf("NO\n");
    }
    
    return 0;
}
 
