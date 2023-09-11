#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <fstream>

using namespace std;



#define inp(n)     cin >> n
//main codes begin here

int n, m;
int b[50001];


void solve()
{
            
}

void input()
{
     inp(n);
     inp(m);
     
     long double d = 0.0, e;
     
     long long int x, y, z;
     for ( int i = 0; i < n; i++ ) {
         inp(b[i]);
     }
     
     for ( int i = 0; i < m; i++ ) {
         inp( x );inp(y);inp(z);
         e = x*x + y*y + z*z;
         e = sqrt( e );
         if ( d < e ) d = e;
     }
     
     int mx = (int)d;
     int ans = 0;
     for ( int i = 0; i < n; i++ ) {
         if ( b[i] > mx ) ans--;
     }
     ans += n;
     
     cout << ans << endl; 
     
     
}
       
int main()
{
    int t = 1;
    inp( t );
    for ( int i = 1; i <= t; i++ ) {
        input();
        solve();
    }
    
    return 0;
}
