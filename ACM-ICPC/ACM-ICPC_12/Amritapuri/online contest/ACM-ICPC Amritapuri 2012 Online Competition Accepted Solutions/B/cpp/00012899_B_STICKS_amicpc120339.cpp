#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int t;
       	int n;
       	int m;

       	long long int a, b, c;

       	long long int diag, count;

	long int L[50001];

	long long int max_d;

	scanf( "%d", &t );
	while ( t-- ) {
		max_d = 0;
		scanf( "%d %d", &n, &m );
		for ( int i = 0; i < n; i++ ) {
			cin >> L[i];
		}
		for ( int i = 0; i < m; i++ ) {
			scanf( "%lld %lld %lld", &a, &b, &c );
			diag = sqrt( a*a + b*b + c*c );
			if ( diag > max_d ) {
				max_d = diag;
			}
		}
		count = 0;
		for ( int i = 0; i < n; i++ ) {
			if ( L[i] <= max_d ) {
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}
