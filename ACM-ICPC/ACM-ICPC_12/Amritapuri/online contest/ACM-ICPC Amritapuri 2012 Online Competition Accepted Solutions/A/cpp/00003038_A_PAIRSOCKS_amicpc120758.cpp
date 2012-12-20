//longest increasing subsequence using DP
/*
8
5 2 8 6 3 6 9 7
o/p length is 4
seq is 2 3 6 9

*/
#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <cstdio> 
#include <string> 
#include <bitset> 
#include <cmath> 
#include <list> 
#include <cstdlib> 
#include <map> 
#include <cstring> 
#include <set> 
#include <stack> 
#include <sstream> 
#include <queue> 
#include <deque> 
#include <ctime> 

using namespace std; 

#define debug(x) cout<<#x<<" = "<<x<<"\n" 
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++) 
#define PI 3.1415926535897932385 
#define INF (1<<29) 
#define EPS (1e-7) 
#define pb push_back 
#define sz size() 
#define ln length() 
#define mp make_pair 
#define all(a) a.begin(),a.end() 
#define fill(ar,val) memset(ar,val,sizeof ar) 
#define sqr(x) ((x)*(x)) 
#define min(a,b) ((a)<(b)?(a):(b)) 
#define max(a,b) ((a)>(b)?(a):(b)) 
#define FORE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++) 

int main() {
    int n,t;
    string s;
    cin >> t;
    while ( t-- ) {
          int r = 0, g = 0 , b = 0, w = 0;
          cin >> s;
          n = s.sz;
          REP(i,n) {
                   if ( s[i] == 'R'  ) r++;
                   if ( s[i] == 'G'  ) g++;
                   if ( s[i] == 'B'  ) b++;
                   if ( s[i] == 'W'  ) w++;
          }
          
          if ( (r % 2 == 0) && ( g % 2 == 0  ) && (b % 2 == 0) && ( w % 2 == 0  ) ) {
               cout << "YES"<< endl;
          } else {
                 cout << "NO"<< endl;
          }
    }
    return 0;
}
