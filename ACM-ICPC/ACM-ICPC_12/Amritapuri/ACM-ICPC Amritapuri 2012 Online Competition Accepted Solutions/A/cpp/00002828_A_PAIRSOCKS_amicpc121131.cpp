#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main()
{
     int t;
     cin >> t;
     for(int i = 0; i < t; i++)
     {
          string inpStr;
          int a[4];
          for(int j = 0; j < 4; j++)
               a[j] = 0;
          cin >> inpStr;
          for(int j = 0; j < inpStr.length(); j++)
          {
               switch(inpStr[j])
               {
               case 'R':
                    a[0]++;
                    break;
               case 'G':
                    a[1]++;
                    break;
               case 'B':
                    a[2]++;
                    break;
               case 'W':
                    a[3]++;
                    break;
               default:
                    break;
               }
          }
          bool print = true;
          
          for(int j = 0; j < 4; j++){
               if (a[j] % 2 != 0)
               {
                    print = false;
                    break;
               }
          }
          if (print)
               cout <<"YES" << endl;
          else
               cout << "NO" << endl;
          
          
     }
     return 0;

}
