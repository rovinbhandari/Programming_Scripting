
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<climits>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

#define REP(i,s,n)  for (int i=(s),_n=(n);i<=_n;i++)
#define FOR(i,s,n)  for (int i=(s),_n=(n);i<_n;i++)
#define REPD(i,e,s)  for (int i=(e),_s=(s);i>=_s;i--)
#define tr(container, it) \
		        for (typeof(container.begin()) it=container.begin(); it!=container.end();it++)
#define PB push_back

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long int n,m;
		cin >> n >> m;
		long long int arr[50100];
		FOR(i,0,n) cin >> arr[i];
		long long int x=0;
		FOR(i,0,m) {
			long long int a,b,c;
			cin >> a >> b >> c;
			x=max(x,a*a+b*b+c*c);
		}
		LL ans=0;
		FOR(i,0,n) {
			if (arr[i]*arr[i] <= x) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
