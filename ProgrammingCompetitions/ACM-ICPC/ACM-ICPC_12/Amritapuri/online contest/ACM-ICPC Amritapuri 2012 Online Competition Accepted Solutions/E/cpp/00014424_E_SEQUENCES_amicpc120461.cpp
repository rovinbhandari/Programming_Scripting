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
// /*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
// */
const int sz = 1e5 + 111;
char S[sz];
int Arr[sz];
int M[sz][20];
int N;
int zero[sz], one[sz];

int inline countZero(int id) {
	return id < 0 ? 0 : zero[id];
}
int inline countOne(int id) {
	return id > N-1 ? 0 : one[id];
}

void preprocess() {
	CL(M, 0);
	forn(i, N)
		M[i][0] = Arr[i];

	for(int j = 1;  (1<<j) <= N; j++) {
		for(int i = 0; i + (1<<j) - 1 < N; i++) {
			M[i][j] = max(M[i][j-1], M[i + (1 << (j-1))][j-1]);
		}
	}

}

int log2(int x) {
	int ret = 0;
	while((1<<ret) <= x)
		ret++;
	return ret-1;
}

int findMax(int l, int r) {
	int k = log2(r-l+1);
	return max(M[l][k], M[r - (1<<k) + 1][k]);

	int ret = Arr[l];
	forab(i, l+1, r)
		ret = max(ret, Arr[i]);
	return ret;
}

int main()
{
	int T;
	read(T);

	while(T--) {
		CL(zero, 0);
		CL(one, 0);
		Sf("%d\n%s\n", &N, S);
		DEBUG(N);
		DEBUG(S);

		zero[0] = (S[0] == '0' ? 1 : 0);
		one[N-1] = (S[N-1] == '1' ? 1 : 0);
		forab(i, 1, N-1)
			zero[i] = zero[i-1] + (S[i] == '0' ? 1 : 0);
		rep(i, N-2, 0)
			one[i] = one[i+1] + (S[i] == '1' ? 1 : 0);
		forn(i, N)
			Arr[i] = one[i] + zero[i];
		preprocess();
/*
		forn(i, N)
			write(zero[i]);
		cout << endl;
		forn(i, N)
			write(one[i]);
		cout << endl;
		forn(i, N)
			write(Arr[i]);
		cout << endl;
*/

		int Q;
		read(Q);
		DEBUG(Q);

		while(Q--) {
			int l, r;
			Sf("%d %d", &l, &r);
			l--; r--;
			DEBUG(l);
			DEBUG(r);
			DEBUG("\n");

			Pf("%d\n", findMax(l, r) - countZero(l-1) - countOne(r+1));
		}
	}

	return 0;
}

