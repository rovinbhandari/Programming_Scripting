#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	string a;
	int t;
	cin >> t;
	for ( int i = 0 ; i < t ; i++ ) {
		cin >> a;
		int r = 0;
		int g = 0;
		int b = 0;
		int w = 0;
		
		for ( int j = 0 ; j < a.length(); j++ ) {
			if ( a[j] == 'R' ) {
				r++;
			}
			if ( a[j] == 'G' ) {
				g++;
			}
			if ( a[j] == 'B' ) {
				b++;
			}
			if ( a[j] == 'W' ) {
				w++;
			}
		}
		
		if ( r % 2 == 0 && g % 2 == 0 && w % 2 == 0 && b % 2 == 0 ) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
