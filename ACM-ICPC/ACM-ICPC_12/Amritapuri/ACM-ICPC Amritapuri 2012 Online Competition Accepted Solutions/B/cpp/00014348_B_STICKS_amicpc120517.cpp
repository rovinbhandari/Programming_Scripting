#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	for ( int i = 0 ; i < t ; i++ ) {
		int m,n;
		cin >> n >> m;
		long long int length[n];
		long long int l,b,h;
		long long int maximum = INT_MIN;
		
		for ( int j = 0 ; j < n ; j++ ) {
			cin >> length[j];
		}
		
		for ( int j = 0 ; j < m ; j++ ) {
			cin >> l >> b >> h;
			maximum = max( maximum, ( long long int)sqrt( l*l + b*b + h*h ) );
		}
		
		int num = 0;
		for ( int j = 0 ; j < n ; j++ ) {
			if ( length[j] <= maximum ) {
				num++;
			}
		}
		
		cout << num << endl;
	}
	return 0;
}
