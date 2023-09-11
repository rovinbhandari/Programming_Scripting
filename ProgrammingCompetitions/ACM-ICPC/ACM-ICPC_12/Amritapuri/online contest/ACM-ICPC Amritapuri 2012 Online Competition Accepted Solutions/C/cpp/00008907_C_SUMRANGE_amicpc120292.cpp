#include <iostream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int t, n, l, h, i ,j ,x, s, e, m, p, q, ans, y;
	scanf( "%d", &t );
	while( t-- ) {
		ans = 0;
		scanf( "%d %d %d", &n, &l, &h );
		vector<int> v(n);
		vector<int> tmp(n);
		vector< vector<int> > vov;
		for( i = 0; i < n; i++ ) {
			scanf( "%d", &x );
			v[i] = x;
			tmp[i] = x;
		}
		sort( tmp.begin(), tmp.end() );
		for( i = 0; i < n; i++ ) {
			s = 0;
			e = tmp.size()-1;
			while( s < e ) {
				m = (s+e)/2;
				if( tmp[m] == v[i] ) break;
				else if( tmp[m] > v[i] ) e = m-1;
				else s = m+1;
			}
			m = (s+e)/2;
			if( tmp[m] > v[i] ) m--;
			else if( tmp[m] < v[i] ) m++;
			tmp.erase( tmp.begin() + m );
			vov.push_back( tmp );
		}
		for( i = 0; i < n-2; i++ ) {
			for( j = i+1; j < n-1; j++ ) {
				x = v[i] + v[j];
				if( x+vov[j][0] <= h && x+vov[j][n-j-2] >= l ) {
					y = l - x;
					s = 0;
					e = n-j-2;
					while( s < e ) {
						m = (s+e)/2;
						if( vov[j][m] == y ) break;
						else if( vov[j][m] > y ) e = m-1;
						else s = m+1;
					}
					m = (s+e)/2;
					if( vov[j][m] < y ) m++;
					p = m;
					y = h - x;
					s = 0;
					e = n-j-2;
					while( s < e ) {
						m = (s+e)/2;
						if( vov[j][m] == y ) break;
						else if( vov[j][m] > y ) e = m-1;
						else s = m+1;
					}
					m = (s+e)/2;
					if( vov[j][m] > y ) m--;
					q = m;
					ans = ans + q - p + 1;
					//printf( "x = %d, p = %d, q = %d\n", x, p, q );
				}
			}
		}
		printf( "%d\n", ans );
	}
	return 0;
}

