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

map<char,int> M;

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    
    string s;
    while(T--){
        M.clear();
        cin >> s;
        REP(i,s.size()) M[s[i]]++;
        if(M['R'] % 2 == 0 and M['G'] % 2 == 0 and M['B'] % 2 == 0 and M['W'] % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
   
    return 0;
}