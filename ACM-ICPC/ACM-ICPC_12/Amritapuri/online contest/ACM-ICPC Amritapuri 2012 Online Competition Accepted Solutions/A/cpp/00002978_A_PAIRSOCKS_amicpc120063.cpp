
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
		string s;
		cin >> s;
		int l=s.size();
		int c1=0,c2=0,c3=0,c4=0;
		FOR(i,0,l) {
			if (s[i]=='R') c1++;
			else if (s[i]=='G') c2++;
			else if (s[i]=='B') c3++;
			else if (s[i]=='W') c4++;
		}
		if (c1%2==0 && c2%2==0 && c3%2==0 && c4%2==0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
