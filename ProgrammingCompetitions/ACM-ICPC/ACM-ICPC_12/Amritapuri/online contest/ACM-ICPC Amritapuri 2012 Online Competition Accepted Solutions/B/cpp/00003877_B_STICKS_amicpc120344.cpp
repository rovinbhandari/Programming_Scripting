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
#include<sstream>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<string>
using namespace std;
typedef long long LL;
template<typename T> T gcd(T a, T b) { return (b == 0) ? abs(a) : gcd(b, a % b); }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T mod(T a, T b) { return (a % b + b) % b; }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> inline string tostring(const T& x) { ostringstream  os; os << x; return os.str(); }

inline int toint(const string& s) { istringstream  is(s); int x; is >> x; return x; }
inline double todouble(const string& s) { istringstream  is(s); double x; is >> x; return x; }
inline string tobinary( int a) { string s; while( a != 0 ) { s = (char)(a%2+'0') + s; a>>=1; } return s; }
inline int isvowel( char c ) { if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) return 1; return 0; }
inline int isprime( int a ) {  for ( int i = 2; i*i <= a; i++ ) if (!(a%i)) return 0; return 1; }

#define s(n)					scanf("%d",&n)
#define sll(n) 					scanf("%lld",&n)
#define sl(n) 					scanf("%ld",&n)
#define ss(n) 					scanf("%s",n)
#define pp(x) printf("%d",x)
#define ppl(x) printf("%ld",x)
#define ppll(x) printf("%lld",x)
#define ps printf(" ")
#define pendl printf("\n")
#define forr(x, b, e)    for (int x = (b); x <= (e); x++)
#define forev(x, b, e)   for (int x = (b); x >= (e); x--)
#define all(c)          (c).begin(), (c).end()
#define mp      make_pair
#define pb      push_back
#define ii      pair<int,int>
#define debug(args...)			{dbg,args; cerr<<endl;}
#define zero(a) memset(a, 0, sizeof(a))
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define MOD 1000000007
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
LL powmod( LL b, LL p,LL m )
{
    LL r = 1;
    for( int i = ( 1 << 30 ); i; i >>= 1 )
    {
        r *= r; r %= m;
        if( p & i ) { r *= b; r %= m; }
    }
    return (LL)r;
}
long long modexp(int n, int p) {
	long long r = 1, b = n;
	while(p > 0) {
		if(p & 1) { r = r * b; if(r >= MOD) r %= MOD; }
		p >>= 1;
		b = b * b; if(b >= MOD) b %= MOD;
	}
	return r;
}

/*Main Code Begins Now*//////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
   //freopen("C:\\Users\\admin\\Desktop\\input.txt","r",stdin);
   //freopen("C:\\Users\\admin\\Desktop\\output.txt","w",stdout);
int test;
cin>>test;
while(test--){
    int N,M;
    s(N);s(M);

double input[N];
double a,b,c;
    forr(i,0,N-1){
        cin>>input[i];
    }
    double m=0;
    forr(i,0,M-1)
    {
		cin>>a>>b>>c;
		
		if(a>m)
		m=a;
		if(b>m)
		m=b;
		if(c>m)
		m=c;
		
	  m=  max(sqrt(a*a+b*b+c*c),m);
		
		
	}
	int cc=0;
	for(int i=0;i<N;i++)
	{
		if(input[i]<=m)
		cc++;
	}
	cout<<cc<<endl;
}
   // system("pause");
  return 0;
}














