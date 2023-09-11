
/* Author Piyush */
//STL includes
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <string>
//C includes
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <ctime>
//Other includes
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;

#pragma comment(linker, "/STACK:16777216")

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define REP(i,n) FOR(i,0,n)
#define V(x) vector< x >
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define fill(a,v) memset(a, v, sizeof(a))
#define PRINT(x) cout << #x << " " << x << endl
#define S(N) scanf("%lld",&N)
#define gc getchar_unlocked
#define sqr(x) (x*x)
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container),element) != container.end())

//Constants
const long double MPI = 3.14159265358979323846264338;
const long double E = 2.71828182845904523536028747;
const int INF = (int) 1e9;

typedef pair<int,int> PI;
typedef pair<int,PI> TRI;
typedef V( int ) VI;
typedef V( PI ) VII;
typedef V( string ) VS;
typedef long long LL;
typedef long double LD;

int main() {
    int t ;
    scanf("%d",&t) ;
    while(t--)
    {
        string s ;
        cin >> s;
        int r = 0;
        int g =0 ;
        int b = 0;
        int w = 0;
        for (int i = 0 ; i < s.size() ;i++)
        {
            if (s[i] == 'R')
                r++;
            if (s[i] == 'G')
                g++;
            if (s[i] == 'B')
                b++;
            if (s[i] == 'W')
                w++;
        }
        if (r%2 == 0 && b%2 == 0 && g%2 == 0 && w%2 == 0)
            cout << "YES" << endl ;
        else
            cout << "NO" << endl;
    }
    return 0;
}
