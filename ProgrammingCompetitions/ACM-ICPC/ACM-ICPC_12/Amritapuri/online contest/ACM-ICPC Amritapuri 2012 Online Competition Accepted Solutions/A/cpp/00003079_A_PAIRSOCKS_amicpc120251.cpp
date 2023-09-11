#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
 
using namespace std;
 
template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }
 
#define FOR(I,A,B)  for(I = (A); I < (B); ++I)
#define REP(I,N)  FOR(I,0,N)
#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 __int64
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
 
const int INF = 0x7f7f7f7f;
 
int main()
{
	int t,n,i,j,a,z, flag;
	vector<int> v(4,0);
	string s;
	cin >> t;
	REP(z,t) {
		REP(i,v.size()) {
			v[i] = 0;
		}
		cin >> s;
		REP(i,s.size()) {
			if(s[i] == 'R')
				v[0]++;
			else if(s[i] == 'G')
				v[1]++;
			else if(s[i] == 'B')
				v[2]++;
			else if(s[i] == 'W') 
				v[3]++;
		}
		
		flag = 0;

		REP(i, v.size()) {
			if(v[i]%2 != 0) {
				flag = 1;
				break;
			}
		}
		if(flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}
