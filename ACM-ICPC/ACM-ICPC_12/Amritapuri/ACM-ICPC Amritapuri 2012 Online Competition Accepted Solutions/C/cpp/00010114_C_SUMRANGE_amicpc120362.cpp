#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <climits>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define SZ(x) ((int)(x).size())
#define FORV(i,x) FOR(i,0,SZ(x))  
#define DBG(x) cout<<(#x)<<" : "<<(x)<<endl
#define PB push_back
#define ALL(x) x.begin(),x.end()

#define ACC(x) accumulate(ALL(x)) 
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)
#define ROFE(i,a,b) for(int i=(b);i>=(a);i--)
#define MP make_pair
#define left(x) (x<<1)
#define right(x) (left(x)+1)
#define PI pair<int,int>
#define PD pair<double,double>
#define F first
#define S second 
#define LL long long
#define ULL unsigned long long

int a[1010], cnt[1000100];

int main()
{
	int cases, n, lo, hi;
	scanf("%d", &cases);
	while(cases --)
	{
		int ret = 0, maxi = 0; memset(cnt, 0, sizeof cnt);
		scanf("%d %d %d", &n, &lo, &hi);
		FOR(i, 0, n) scanf("%d", &a[i]), cnt[a[i]] ++, maxi = max(maxi, a[i]);
	
		FOR(i, 1, maxi + 1) cnt[i] += cnt[i - 1];
		
		FOR(i, 0, n)
			FOR(j, 0, n) if(j != i)
			{
				int tlo = max(lo - a[i] - a[j], 1);
				int thi = min(hi - a[i] - a[j], maxi);
				if(thi <= 0) continue;
				
				int lcnt = cnt[tlo - 1];
				int hcnt = cnt[thi];
				
				if(a[i] <= tlo - 1) lcnt --;
				if(a[i] <= thi) hcnt --;
				if(a[j] <= tlo - 1) lcnt --;
				if(a[j] <= thi) hcnt --;
				
				ret += hcnt - lcnt;
			}
		
		printf("%d\n", ret / 6);
	}
	
	return 0;
}