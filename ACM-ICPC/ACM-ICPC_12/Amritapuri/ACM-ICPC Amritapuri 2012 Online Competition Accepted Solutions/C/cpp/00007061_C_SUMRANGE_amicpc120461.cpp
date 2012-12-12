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
const int sz = 1e3 + 111;
int A[sz];
int N, L, H;

int findLeft(int l, int r, int v) {
	while(l < r) {
		int mid = (l+r)/2;

		if(A[mid] >= v)
			r = mid;
		else
			l = mid+1;
	}

	if(A[l] >= v)
		return l;
	return N;
}

int findRight(int l, int r, int v) {
	while(l < r) {
		int mid = (l+r+1)/2;

		if( A[mid] <= v)
			l = mid;
		else
			r = mid-1;
	}

	return l;
}

int main()
{
	int T;
	read(T);

	while(T--) {
		Sf("%d %d %d", &N, &L, &H);
//		DEBUG(N);
//		DEBUG(L);
//		DEBUG(H);
		forn(i, N)
			read(A[i]);
		sort(A, A+N);
/*
		cout << "Arr: " ;
		forn(i, N)
			Pf("%2d ", A[i]);
		cout << endl;
		Pf("Idx: ");
		forn(i, N)
			Pf("%2d ", i);
		cout << endl;
		cout << endl;
*/
		int ans = 0;

		forn(i, N) {
			forab(j, i+1, N-2)	if(A[i] + A[j] <= H) {
				int left = findLeft(j+1, N-1, L - A[i] - A[j]);
				int right = findRight(j+1, N-1, H - A[i] - A[j]);
				if(A[i] + A[j] + A[left] < L || A[i] + A[j] + A[right] > H)
					continue;

//				Pf("i = %d, j = %d, left = %d, right = %d, range = %d\n", i, j, left, right, right - left + 1);

				ans += (right - left + 1);
			}
		}
		Pf("%d\n", ans);
//		DEBUG(ans);
	}

	return 0;
}

