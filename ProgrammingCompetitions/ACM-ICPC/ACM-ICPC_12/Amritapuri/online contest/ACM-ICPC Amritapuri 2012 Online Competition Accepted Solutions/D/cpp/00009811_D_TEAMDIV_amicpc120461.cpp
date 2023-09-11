//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl		("\n")
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

const int sz = 2e4 + 111;
const int64 mod = (int64)1e9 + 7;
int color[sz];
int N;

set <int> G[sz];

bool isValid;

void dfs(int u, int c) {
	if(isValid == false)
		return;
	if(color[u] != 0) {
		if(color[u] != c)
			isValid = false;
		return;
	}
	color[u] = c;
	c = c == 1 ? 2 : 1;

	tr(it, G[u])
		dfs(*it, c);
}

int main()
{
	int T;
	read(T);

	while(T--) {
		read(N);
		forn(i, N)
			G[i].clear();

		forn(i, N) {
			int K;
			read(K);

			while(K--) {
				int tmp;
				read(tmp);
				G[i].insert(tmp);
				G[tmp].insert(i);
			}
		}
/*
		cout << "Graph : \n";
		forn(i, N) {
			cout << i << ": ";
			tr(it, G[i])
				write(*it);
			cout << endl;
			cout << endl;

		}
	*/
		CL(color, 0);
		isValid = true;
		int64 ans = 1;

		forn(i, N) {
			if(isValid == false) {
				break;
			}
			if(color[i] != 0)
				continue;
			ans = (ans * 2) % mod;
			color[i] = 1;

			tr(it, G[i]) {
				dfs(*it, 2);
			}
		}
		
		Pf("%lld\n", (isValid == false) ? 0ll : ans);
	}

	return 0;
}

