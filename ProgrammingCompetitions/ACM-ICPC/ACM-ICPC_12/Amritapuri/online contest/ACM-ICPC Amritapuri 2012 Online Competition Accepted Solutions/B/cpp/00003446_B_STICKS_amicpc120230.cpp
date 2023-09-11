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

LL len[50005];

int main()
{
	//fii; fio;
	int testCases, t = 0;

	scanf("%d", &testCases);
	int n, m;
	LL a, b, c;
	while (testCases--) {
        scanf("%d %d", &n, &m);
        for (int i=0; i<n; i++)
            scanf("%lld", &len[i]);

        LL maxi = 0;
        for (int i=0; i<m; i++) {
            scanf("%lld %lld %lld", &a, &b, &c);
            LL diag = a*a + b*b + c*c;
            maxi = max(maxi, diag);
        }

        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (maxi - len[i] * len[i] >= 0)
                cnt++;
        }

        cout << cnt << endl;
	}
	return 0;
}
