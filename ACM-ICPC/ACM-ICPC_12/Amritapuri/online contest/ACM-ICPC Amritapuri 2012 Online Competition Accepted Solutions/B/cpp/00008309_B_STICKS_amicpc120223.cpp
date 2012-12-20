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
#include <ctime>
#include <string.h>
using namespace std;

#define rep(i,a) for((i)=0;(int)(i)<(a);(i)++)
#define rrep(i,a,b) for((i)=(a);(i)>=(b);(i)--)
#define maX(a,b) ((a)>(b)?(a):(b))
#define miN(a,b) ((a)<(b)?(a):(b))
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pss pair<string,string>
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define re return
#define sz(x) ((int)(x).size())
#define vi vector<int>
#define vs vector<string>
#define vpii vector< pii >

template<class T> T abs(T x){return x>0?x:-x;}
inline int toInt(string s) {int v;istringstream sin(s);sin>>v;return v;}
inline ll toll(string s) {ll v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}
template<class T> inline T gcd(T a,T b) {if (a<0) a=-a;if (b<0) b=-b;return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {return a*(b/gcd(a,b));}
ll L[100010];
int main()
{
	ll N,M,D,d,a,b,c;
	int test;
	scanf("%d",&test);
	while(test--){
	int i;
	scanf("%lld%lld",&N,&M);
	rep(i,N){
		scanf("%lld",&L[i]);
	}
	D=0;
	rep(i,M){
		scanf("%lld%lld%lld",&a,&b,&c);
		d=(ll)sqrt(a*a+b*b+c*c);
		D=maX(D,d);
	}
	sort(L,L+N);
	int res=upper_bound(L,L+N,D)-L;
	printf("%d\n",res);
	}
	return 0;
}



