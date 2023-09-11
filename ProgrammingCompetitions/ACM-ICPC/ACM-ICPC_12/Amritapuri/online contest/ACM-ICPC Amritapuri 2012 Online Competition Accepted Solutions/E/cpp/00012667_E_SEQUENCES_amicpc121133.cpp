#include <iterator>
#include <cctype>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <climits>
#include <limits>
#include <string>
using namespace std;

//Macros
#define dbl double
#define fl float
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define vi vector<int>
#define vll vector<ll>

#define abs(x) ((x)<0?-(x):(x))
#define sqr(x) ((x)*(x))

#define MOD 1000000007
#define MAXN 300010
#define MAXBUF 100000
#define EPS 1e-9
#define NIL 0
#define INF (INT_MAX/2)
#define LLINF (LONG_LONG_MAX/2LL)
#define NEWLINE '\n'

#define SET(A) memset(A, 1,sizeof(A));                     //NOTE: Works only for x = 0 and -1. Only for integers.
#define CLR(A) memset(A, 0,sizeof(A));
#define MEM(A,x) memset(A,x,sizeof(A));
#define CPY(A,B) memcpy(A,B,sizeof(A));

#define SIZE(A) ((int)(A.size()))
#define ALL(x)  x.begin(),x.end()
#define FILL(A,x) fill(ALL(A),x)
#define REP(i,N) for(int i=0;i<(int)(N); ++i)
#define FORab(i,a,b) for(int i=(int)(a);i<=(int)(b); ++i)
#define RFORab(i,a,b) for(int i=(int)(a);i>=(int)(b); --i)
#define FOR1(i,n) FORab(i,1,(n))
#define RFOR1(i,n) RFORab(i,(n),1)
#define FOR(i,n) FORab(i,0,(n)-1)
#define RFOR(i,n) RFORab(i,(n)-1,0)
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define SORTV(x) sort(ALL(x))
#define REVV(x) reverse(ALL(x))

#define GI ({int t;scanf("%d",&t);t;})                  //NOTE: Don't comma separate two inputs.
#define GLL ({long long t;scanf("%lld",&t);t;})          //NOTE: Don't comma separate two inputs.
#define GLD ({double t;scanf("%lf",&t);t;})              //NOTE: Don't comma separate two inputs.

#define MP make_pair
#define PB push_back
#define ff first
#define ss second

#define nbits(n) __builtin_popcount(n)                  //NOTE: Works only for int. Write your own function for long long :-/
#define atbit(x,i) (((x)>>(i))&1)
#define FIXMOD(a) (((a)%MOD+MOD)%MOD)

#define   debug(x)              if(!SUBMIT){ cout<<"-> "<<#x<<" = "<<x<<"\n";}
#define   debugv(x)             if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x))cout<<x[i]<<" ";cout<<"\n";}
#define   debugvv(x)            if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x)){REP(j,SIZE(x[i])){cout<<x[i][j]<<" ";}cout<<"\n";}}
#define   debug1(A,N)           if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,N)cout<<A[i]<<" ";cout<<"\n";}
#define   debug2(A,R,C)         if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,R){REP(j,C){cout<<A[i][j]<<" ";}cout<<"\n";}}

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

//template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (a > b ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
//template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool BTW(T a, T b, T c) { return a<=b && b<=c; }         // To check whether b is in [a,c]
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }                 // set max(a,b) to a
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }                 // set min(a,b) to b

#define SUBMIT false                                    //NOTE: Set this to true before submitting

int ones[MAXN];
int zeros[MAXN];
int bees[MAXN];
char lst[MAXN];
int size;

void initialize(int node, int b, int e )
{
//	cout<<"INI "<<node<<" "<<b<<" "<<e<<endl;
	if (b == e)
	{
		if( b > size )
		{
			ones[node] = 0;
			zeros[node] = 0;
			bees[node] = 0;
		}
		else
		{
			ones[node] = (lst[b] == '1' ? 1 : 0);
			zeros[node] = (lst[b] == '0' ? 1 : 0);
			bees[node] = 1;
		}
	}

	else
	{
		//compute the values in the left and right subtrees
		initialize(2 * node, b, (b + e) / 2);
		initialize(2 * node + 1, (b + e) / 2 + 1, e);
		//search for the minimum value in the first and
		//second half of the interval

		zeros[node] = zeros[2*node] + zeros[2*node+1];
		ones[node] = ones[2*node] + ones[2*node+1];

		bees[node] = max(zeros[node], max( ones[node], max(zeros[2*node] + ones[2*node+1], max(zeros[2*node] + bees[2*node+1], bees[2*node] + ones[2*node+1]))));
//		cout<<"VAL "<<node<<" "<<zeros[node]<<" "<<ones[node]<<" "<<bees[node]<<endl;


	}
}

pair <int, pair <int, int> > query(int node, int b, int e, int i, int j)
{
//	if( i==6 && j== 10)
//		cout<<"TR "<<node<<" "<<b<<" "<<e<<endl;
	//if the current interval doesn't intersect 
	//the query interval return -1
	if (i > e || j < b)
		return make_pair(-1, make_pair(-1, -1));

	//if the current interval is included in 
	//the query interval return M[node]
	if (b >= i && e <= j)
	{
//		if( i==6 && j==10)
//			cout<<"HA "<<node<<" "<<bees[node]<<" "<<zeros[node]<<" "<<ones[node]<<" "<<endl;
		return make_pair(bees[node], make_pair(zeros[node], ones[node]));
	}

	//compute the minimum position in the 
	//left and right part of the interval
	pair <int, pair <int, int> > p1 = query(2 * node, b, (b + e) / 2, i, j);
	pair <int, pair <int, int> > p2 = query(2 * node + 1, (b + e) / 2 + 1, e,i, j);

	//return the position where the overall 
	//minimum is
	if (p1.first == -1)
		return p2;
	if (p2.first == -1)
		return p1;
	
	pair <int, pii> sol;
	sol.second.first = p1.second.first + p2.second.first;
	sol.second.second = p1.second.second + p2.second.second; 

	sol.first = max(sol.second.first, sol.second.second);
	sol.first = max(sol.first, p1.second.first + p2.second.second);
	sol.first = max(sol.first, p1.second.first + p2.first);
	sol.first = max(sol.first, p1.first + p2.second.second);
//	bees[node] = max(zeros[node], max( ones[node], max(zeros[2*node] + ones[2*node+1], max(zeros[2*node] + bees[2*node+1], bees[2*node] + ones[2*node+1]))));

//	if( i == 6 && j == 10 )
//		cout<<"HA "<<node<<" "<<sol.first<<" "<<sol.second.first<<" "<<sol.second.second<<" "<<endl;
	return sol;
}



int main()
{
	int c, n, k, t, e, i;
	scanf("%d", &c);
	while(c--)
	{
		scanf("%d", &n);
		size = n;
		scanf("%s", lst+1);
//		printf("%s\n", lst+1);
		initialize(1, 1, n);

//		for( i=0;i<3*n;i++)
//			cout<<" B "<<i<<" "<<bees[i]<<" "<<ones[i]<<" "<<zeros[i]<<endl;

//		cout<<"__________"<<endl;

		scanf("%d", &k);
		for( i = 0; i < k; ++i)
		{
			scanf("%d %d", &t, &e);
			pair <int, pair<int, int> > tmp = query(1, 1, n, t, e);
			printf("%d\n", tmp.first);
		}
	}
	return 0;
}
