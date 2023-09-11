#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int t, i;
    char s[52];
    int r, b, g, w, k;
    
    scanf("%d", &t);
    
    while (t--) {
          scanf("%s", s);
          k = 0;
          r = 0;
          b = 0;
          g = 0;
          w = 0;
          if (strlen(s)%2 == 0) {
          
          for (i = 0; i < strlen(s); i++) {
              if (s[i] == 'R') {
                 r++;
              } else if (s[i] == 'W') {
                     w++;
              } else if(s[i] == 'G') {
                     g++;
              } else if(s[i] == 'B') {
                     b++;
              }
          }
          
          if (r%2 != 0) {
                  k = 1;
          } else if (g%2 != 0) {
                 k = 1;
          } else if (w%2 != 0) {
                 k = 1;
          } else if (b%2 != 0) {
                 k = 1;
          } else {}
          } else {
                 k = 1;
          }
          
          if (k == 1) {
                printf("NO\n");
          } else {                
                 printf("YES\n");
          }
    }
    
  
    return 0;
}
