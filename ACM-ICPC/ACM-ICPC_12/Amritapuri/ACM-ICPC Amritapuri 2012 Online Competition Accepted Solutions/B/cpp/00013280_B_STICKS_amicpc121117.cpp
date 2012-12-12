//============================================================================
// Name        : ACMamritaonlineB.cpp
// Author      : vivek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define FOR(i,a,b)				for(int i=a;i<b;i++)
#define REP(i,n)				FOR(i,0,n)
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define FF						first
#define SS						second
#define tri(a,b,c)				mp(a,mp(b,c))
#define XX						first
#define YY						second.first
#define ZZ						second.second
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define SZ(v)					((int)(v.size()))
#define DREP(a)					sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())
#define debug(args...)			{dbg,args; cerr<<endl;}
#define dline					cerr<<endl

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, PII> TRI;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;

/*Main code begins now */

int main() {
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
	int T;
	s(T);
	while (T-- > 0) {
		int stick, box;
		s(stick);
		s(box);
		long long st[50000];
		for (int i = 0; i < stick; i++) {
			sl(st[i]);
		}
	//	sort(&st[0],&st[0]+stick);
		long long a[3];long long max=0;
		for (int j=0; j < box; j++) {
			sl(a[0]);
			sl(a[1]);
			sl(a[2]);
			long long d = a[0]*a[0] + a[1] * a[1] + a[2] * a[2];
			if(d>max)
				max=d;
		}
		int count=0;
		for(int k=0;k<stick;k++){
			if(st[k]*st[k]<=max){
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
