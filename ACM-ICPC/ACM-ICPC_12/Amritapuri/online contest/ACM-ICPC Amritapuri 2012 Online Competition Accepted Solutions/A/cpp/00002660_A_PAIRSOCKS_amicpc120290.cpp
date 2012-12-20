#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include<stdio.h>
using namespace std; 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
              string s;
              cin>>s;
              int l=s.length();
              int r=0,g=0,b=0,w=0;
              for(int i=0;i<l;i++){
                      if(s[i]=='R')
                        r++;
                      else if(s[i]=='G')
                        g++;
                      else if(s[i]=='B')
                           b++;
                      else
                          w++;
                          }
                      if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
                        cout<<"YES\n";
                      else
                        cout<<"NO\n";
              }
              return 0;
                      
                      
    
    
    
}
