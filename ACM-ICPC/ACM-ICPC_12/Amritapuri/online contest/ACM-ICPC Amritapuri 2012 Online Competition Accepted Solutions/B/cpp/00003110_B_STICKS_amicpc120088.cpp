
/*
 * Author: blackBird
 * Email: saketbharamberocks@gmail.com
 */
#include <cstdio>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <climits>

using namespace std ;

typedef long long ll ;
typedef pair<int,int> ii ;

#define FOR(i,a,b) for(int i=(a);i<(b);i++) 
#define FOR0(i,a) for(int i=0;i<(a);i++) 
#define FOR1(i,a) for(int i=1;i<(a);i++)
#define REP(i,a,b,c) for(int i=(a);i<(b);i+=(c)) 
#define TRAVERSE(it,s) for(typeof(s.begin()) it=s.begin();it!=s.end();++it)
#define ENDL putchar(10)
#define PB push_back
#define MP make_pair
#define SZ size

#define FILL(a,x) memset(a,x,sizeof a)
#define ALL(c) (c).begin(),(c).end()
#define PRESENT(c,x) (find(ALL(c),x) != (c).end())

#define ABS(a) ((a)<0?-(a):(a))
#define SQ(x) (x)*(x)
#define INF 0xffffff00
#define ESP 1e-6

#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MININ(a) *min_element(a.begin(), a.end())
#define MININ_A(a,n) *min_element(a, a+n)
#define MAXIN(a) *max_element(a.begin(), a.end())
#define MAXIN_A(a,n) *max_element(a, a+n)

#define P(x) cout << x 
#define PE(x) cout << x << endl 
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SLL ({long long _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
#define SC getchar()
#define SS(n) scanf("%s",n)

ll L[50123] ; 

void solve() { 
	int n = SI ;
	int m = SI ;
	FOR0(i,n) { L[i] = SLL ; } 
	ll maxl = -1 ; 
	FOR0(i,m) { 
		ll a,b,c ;
		cin >> a >> b >> c ;
		ll d = a*a + b*b + c*c ; 
		maxl = max(maxl, d); 
	}
	int ans = 0 ;
	FOR0(i,n) { 
		if ( L[i]*L[i] <= maxl ) { ans ++ ; } 
	}
	PE(ans);
}	

int main () {
	int t = SI ;
	while ( t-- ) { solve() ;} 
	return 0 ;
}

/*
ifstream in ("input.txt");
cin.rdbuf(in.rdbuf());
ofstream out ( "output.txt") ;
cout.rdbuf(out.rdbuf());
*/
