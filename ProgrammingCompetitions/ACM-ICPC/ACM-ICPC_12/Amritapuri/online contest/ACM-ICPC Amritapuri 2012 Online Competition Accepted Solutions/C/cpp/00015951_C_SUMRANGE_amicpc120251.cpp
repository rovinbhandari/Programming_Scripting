/*
 * 3.cpp
 *
 * Copyright (C) 2012 whitepearl
 */

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

#define FOR(I,A,B)  for(int I = (A); I < (B); ++I)
#define REP(I,N)  FOR(I,0,N)

const int INF = 0x7f7f7f7f;
typedef long long int lli;

int main()
{
	int t,cnt;
	int n, l, h;
	int i,j,k, s1, x,f;
	int a[1001];

	cin >> t;

	while(t--) {
		cnt = 0;
		cin >> n >> l >> h;
		FOR( z, 0, n ) {
			cin >> a[z];
		}
		sort(a, a+n);

		FOR( i, 0, n ) {
			j = i+1;
			k = n-1;
			while( j < k ) {
				s1 = a[i]+a[j];
				if( s1+a[k]-l < 0) {
					j++;
				}
				if( s1+a[k]-l >= 0) {									
					if ( s1 + a[k] - h <= 0) {
					//	cout << a[i] << " " << a[j] << " " << a[k] << endl;
						cnt++;
						x = j+1;
						while( x < k ) {
							s1 = a[i]+a[x];
							if( s1+a[k]-l >= 0) {
			                                        if ( s1 + a[k] - h <= 0) {
                        		     //                   cout << "dff" << a[i] << " " << a[x] << " " << a[k] << endl;
                                        		        cnt++;
								x++;
								}
								else {
									break;
								}
							}
						}
						k--;
					}else{ 
						k--;
					}
				}
				if( j >= k ) {
					//cout << "in " << i << " " << j << " " << k << endl;
					j = i+1;
					k--;
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}

