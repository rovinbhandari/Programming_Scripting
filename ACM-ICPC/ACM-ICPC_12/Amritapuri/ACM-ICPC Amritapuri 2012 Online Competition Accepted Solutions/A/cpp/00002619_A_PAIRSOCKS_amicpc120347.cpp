/*
	ID: goyal.a1
	LANG: C++
	TASK: 
*/
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
#define FOR(i,a,b)  for(int (i) = (a);(i)<(b);(i)++)
#define   REP(i,n) FOR(i,0,n)
#define  INF (1<<29)
#define         pb push_back
#define 	     sz size()
#define         mp make_pair
#define all(a) a.begin(),a.end()
#define SI(n)               scanf("%d",&n);
#define SL(n)               scanf("%lld",&n);
#define fill(ar,val) memset(ar,val,sizeof ar)
#define FORE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>  pii;
typedef vector<string> vs;
ll s2i(string s) { istringstream iss(s); ll x;iss>>x; return x;}
string i2s(ll x) { ostringstream oss; oss<<x; return oss.str();}
/* Main code begins now */

int main()
{
//	freopen("","r",stdin);
//	freopne("","w",stdout);

	int t;
	cin >> t;
	while ( t-- ) {
		string s;
		cin >> s;
		map < char,int > m;
		for ( int i = 0; i < s.size(); i++)
			m[s[i]] += 1;

		if ( (m['R']%2  == 0) && (m['G']%2 == 0) && (m['W'] % 2 == 0) && (m['B']%2 == 0) )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}



	
