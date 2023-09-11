#include <iostream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	int t, n, m, i, p, k;
	int a[50010];
	long long int x, y, z, max, tmp;
	scanf( "%d", &t );
	while( t-- ) {
		max = 0;
		p = 0;
		scanf( "%d %d", &n, &m );
		for( i = 0; i < n; i++ ) {
			scanf( "%d", &a[i] );
		}
		for( i = 0; i < m; i++ ) {
			scanf( "%lld %lld %lld", &x, &y, &z );
			tmp = sqrt( x*x + y*y + z*z );
			if( tmp > max ) {
				max = tmp;
			}
		}
		p = 0;
		for( i = 0; i < n; i++ ) {
			if( a[i] <= max ) p++;
		}
		printf( "%d\n", p );
	}
	return 0;
}
