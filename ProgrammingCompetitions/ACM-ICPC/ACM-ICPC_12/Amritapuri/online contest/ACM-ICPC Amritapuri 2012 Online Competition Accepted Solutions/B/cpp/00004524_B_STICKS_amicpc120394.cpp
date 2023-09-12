#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;i++)
#define FOR(i,a,n) for(int i=(int)a;i<(int)n;i++)
#define FOR1(i,n) for(int i=1;i<=(int)n;i++)
#define ALL(c) c.begin(),c.end()
#define FORE(it,c) for(typeof(c.begin()) it=c.begin();it!=c.end();it++)

typedef long long int lli;
typedef pair<int,int> ii;

const int N = 50010;
lli L[N];


int main(){
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    
    while(T--){
        int n, m;
        cin >> n >> m;
        REP(i,n) {
            cin >> L[i];
            L[i] *= L[i];
        }
        lli d = 0;
        lli a, b, c;
        REP(i,m) {
            cin >> a >> b >> c;
            d = max(d,(a*a) + (b*b) + (c*c));
        }

        int ans = 0;
        REP(i,n) if(L[i] <= d) ans++;
        cout << ans << "\n";
    }
   
    return 0;
}