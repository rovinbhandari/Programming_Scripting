#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cfloat>
#include <climits>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <sys/time.h>

#define INF 1000000007
#define EPS (1e-8)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define mp make_pair
#define FOR(i,k) for(i=0;i<k;i++)
#define RFOR(i,k) for(i=k-1;i>=0;i--)
const long double PI = 3.1415926535897932384626433832795;
typedef long long LL;


using namespace std;


int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int i, j, n, l, h;
		int a[1001];
		scanf("%d %d %d", &n, &l, &h);
		for(i=0; i<n; i++) scanf("%d", &a[i]);
		long long int count = 0;
		sort(a, a+n);
		for(i=0; i<n; i++)
		{
			int lb = n;
			int hb = n;
			for(j=i+1; j<n; j++)
			{
				int sum = a[i] + a[j];
				while(sum + a[lb-1] >= l) lb--;
				while(sum + a[hb-1] > h) hb--;
				if(lb <= j ) lb = j+1; if(hb <= j) break;
				int diff = hb - lb;
//				cout << a[i] << ' ' << a[j] << ' ' << lb << ' ' << hb << ' ' << diff << endl;
				if(diff > 0) count = count + diff;
			}
		}
		printf("%lld\n", count);
		
	}
	return 0;
}

