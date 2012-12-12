// Author: Nishant R. Krishan
#include <iostream>
#include <sstream>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>

using namespace std;
#define VI vector < int >
#define VVI(A,N,M) vector< VI > A( N, VI (M) )
#define LL long long
#define LLU unsigned long long int
#define SI ({int x;scanf("%d",&x);x;})
#define SC ({char x;scanf("%c",&x);x;})
#define SLL ({LL x;scanf("%lld",&x);x;})
#define SLLU ({LLU x;scanf("%llu",&x);x;})
#define PI acos(-1)
#define ALL(c) (c).begin(), (c).end() 
#define SORT(c) sort(ALL(c)) 
#define X first 
#define Y second
#define MP make_pair
#define PB push_back
#define SET(v,i) memset(v, i, sizeof(v))
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (a); i > (b); i--)
#define FORN(i,a,b) for (int i = (a); i <= (b); i++)
#define DOWN(i,a,b) for (int i = (a); i >= (b); i--)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define INF 1000000007

int main(int argc, char** argv) {
	LL T=SLL,N,M,A,B,C,Tmp,i,MA,Ans;
	vector<LL> L;
	while( T-- ){
		MA=0;
		Ans=0;
		N=SLL,M=SLL;
		L.clear();
		for( i=0;i<N;i++ ){
			Tmp=SLL;
			L.PB(Tmp);
		}
		for( i=0;i<M;i++ ){
			A=SLL,B=SLL,C=SLL;
			Tmp = A*A + B*B + C*C;
			Tmp = sqrt(Tmp);
			MA = max( MA, Tmp );
		}
		for( i=0;i<N;i++ ){
			if( L[i]<=MA )
				Ans++;
		}
		printf("%lld\n",Ans);
	}
	return 0;
}

