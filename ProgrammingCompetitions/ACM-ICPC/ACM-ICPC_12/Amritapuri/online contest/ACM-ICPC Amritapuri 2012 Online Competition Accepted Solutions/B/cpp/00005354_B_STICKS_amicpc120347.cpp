#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <cmath>
#include <list>
#include <cstdlib>
#include <map>
#include <cstring>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <ctime>

using namespace std;

#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define   REP(i,n) for(int(i)=0;(i)<(n);(i)++)
#define  INF (1<<29)
#define         pb push_back
#define 	     sz size()
#define         mp make_pair
#define 	all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<string> vs;
ll s2i(string s) { istringstream iss(s); ll x;iss>>x; return x;}
string i2s(ll x) { ostringstream oss; oss<<x; return oss.str();}
int ar[50005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, m;
		scanf("%d%d",&n,&m);

		REP(i,n) scanf("%d",&ar[i]);
		ll h = 0;
		ll a, b, c;
		REP(i,m) {
			scanf("%lld%lld%lld",&a,&b,&c);
			ll hyp = sqrt(a*a + b*b + c*c);
			h = max(h,hyp);
		}
		int ans = 0;
		REP(i,n) if(ar[i] <= h) ans++;
		cout << ans << endl;
	}
	return 0;
}

