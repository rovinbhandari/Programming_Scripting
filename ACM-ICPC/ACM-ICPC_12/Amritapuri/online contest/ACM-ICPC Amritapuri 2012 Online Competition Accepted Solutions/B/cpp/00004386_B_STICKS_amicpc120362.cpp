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

#define FOR(i,a,b) for(LL i=(a);i<(b);i++)
#define SZ(x) ((int)(x).size())
#define FORV(i,x) FOR(i,0,SZ(x))  
#define DBG(x) cout<<(#x)<<" : "<<(x)<<endl
#define PB push_back
#define ALL(x) x.begin(),x.end()

#define ACC(x) accumulate(ALL(x)) 
#define FORE(i,a,b) for(LL i=(a);i<=(b);i++)
#define ROFE(i,a,b) for(LL i=(b);i>=(a);i--)
#define MP make_pair
#define left(x) (x<<1)
#define right(x) (left(x)+1)
#define PI pair<int,int>
#define PD pair<double,double>
#define F first
#define S second 
#define LL long long
#define ULL unsigned long long

LL L[50050], aL[100100];
LL diag[50050];

#define eps 1e-9
 
int main()
{
	LL cases, n, m, res, l, b, h, maxi;
	scanf("%lld", &cases);
	while(cases --)
	{
		res = 0, maxi = 0;
		scanf("%lld %lld", &n, &m);
		FOR(i, 0, n) scanf("%lld", &L[i]);
		
		FOR(i, 0, m)
		{
			scanf("%lld %lld %lld", &l, &b, &h);
			diag[i] = (l * l + b * b + h * h);
			maxi = max(maxi, diag[i]);
		}
		
		FOR(i, 0, n) res += (maxi >= L[i] * L[i]);
		
		printf("%lld\n", res);
	}
	
	return 0;
}