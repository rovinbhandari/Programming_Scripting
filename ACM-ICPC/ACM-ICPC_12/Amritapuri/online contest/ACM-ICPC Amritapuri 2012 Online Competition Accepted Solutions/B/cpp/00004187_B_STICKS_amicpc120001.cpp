#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

typedef long long ll;
#define debug(args...) dbg(),args
#define S(N) scanf("%d",&N)
#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define PB(A,B) A.push_back(B);
#define ALL(A) A.rbegin(),A.rend()
#define MEM(A,B) memset(A,B,sizeof(A))
#define MAX(A,B) (A > B) ? A : B
#define MIN(A,B) (A < B) ? A : B
#define DBGCHECK if (argc > 1) DBG = ((*argv[1] == '0') ? 0 : 1)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define LIM 5000001
#define MOD 1000000007
bool DBG;
struct dbg { template<typename T> dbg& operator , (const T& v) { if (DBG) cerr << v << " "; return *this; } ~dbg() { if (DBG) cerr << endl; } };

int main (int argc, char *argv[])
{
DBGCHECK;
int t;
cin >> t;
while(t--) {

int n,m,ans = 0;
cin >> n >> m;

long long a, b, c, d, max = 0, sticks[n];

for (int i = 0; i < n; ++i)
{
cin >> sticks[i];
}

for (int i = 0; i < m; ++i)
{
cin >> a >> b >> c;
d = a*a + b*b + c*c;
if(d > max)
max = d;
}

for (int i = 0; i < n; ++i)
{
if(sticks[i]*sticks[i]<=max)
++ans;
}

cout << ans << endl;

}

return 0;
}