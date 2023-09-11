#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <sstream>


#define pb(x) push_back(x) 

using namespace std;

typedef long long int ll;

int main()
{
	int t;

	cin >> t;
	int r,b,g,w;

	while( t-- ) {
		r = b = g = w = 0;

		string s;
		cin >> s;

		for( int i = 0; i < s.length(); i++ ) {
			if( s[i] == 'R' )
				r++;
			else if( s[i] == 'B' )
				b++;
			else if( s[i] == 'G' )
				g++;
			else if( s[i] == 'W' )
				w++;
		}

		if( r % 2 == 0 && b % 2 == 0 && g % 2 == 0 && w % 2 == 0 )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}

