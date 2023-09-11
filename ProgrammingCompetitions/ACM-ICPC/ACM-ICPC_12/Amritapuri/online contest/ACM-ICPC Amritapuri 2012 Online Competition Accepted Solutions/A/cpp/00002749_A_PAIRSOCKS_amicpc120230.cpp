#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

#define REP(i,n)      FOR(i,0,n)
#define FOR(i,a,b)    for(int i = a; i < b; i++)
#define ROF(i,a,b)    for(int i=a;i>b;i--)
#define min(a,b)      (a<b?a:b)
#define max(a,b)      (a>b?a:b)
#define GI 		      ({int t;scanf("%d",&t);t;})
#define GL 		      ({LL t;scanf("%lld",&t);t;})
#define GD 		      ({double t;scanf("%lf",&t);t;})
#define pb 	          push_back
#define mp 	          make_pair
#define fii 	      freopen("input.txt","r",stdin)
#define fio 	      freopen("output.txt","w",stdout)
#define MOD 	      1000000007
#define INF	          (int)1e9
#define EPS	          1e-9
#define TR(a,it)      for (typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

string str;

int main()
{
	//fii; fio;
	int testCases, t = 0;

	scanf("%d", &testCases);
	while (testCases--) {
        cin >> str;
        int r = 0, g = 0, b = 0, w = 0;
        for (int i=0; i<str.size(); i++) {
            if (str[i] == 'W') w++;
            else if (str[i] == 'R') r++;
            else if (str[i] == 'B') b++;
            else if (str[i] == 'G') g++;
        }

        if (w % 2 == 0 && r % 2 == 0 && b % 2 == 0 && g % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
	}
	return 0;
}
