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
	int r,g,b,w,t, i;
	string s;
	scanf( "%d", &t );
	while( t-- ) {
		cin >> s;
		r = g = b = w = 0;
		for( i = 0; i < s.size(); i++ ) {
			if( s[i] == 'R' ) r++;
			else if( s[i] == 'G' ) g++;
			else if( s[i] == 'B' ) b++;
			else if( s[i] == 'W' ) w++;
		}
		if( r%2 == 0 && g%2 == 0 && b%2 == 0 && w%2 == 0) puts( "YES" );
		else puts( "NO" );
	}
	return 0;
}
