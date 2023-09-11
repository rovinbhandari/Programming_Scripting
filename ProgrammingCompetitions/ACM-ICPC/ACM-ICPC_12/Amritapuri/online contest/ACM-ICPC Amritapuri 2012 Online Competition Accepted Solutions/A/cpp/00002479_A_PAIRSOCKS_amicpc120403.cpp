/*************
	Team - ThePrestige
****************/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

#define rep(i,a,b) for(typeof(a) i=(a);i<(b);i++)
#define ll long long int
#define ii pair<int,int>
#define gi(x) scanf("%d",&x)
#define Clear(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()


int main()
{
	int T; gi(T);
	while( T--  ) {
		string s; cin >> s;
		int sz= SZ(s);
		int r = 0, g = 0 , b = 0 , w = 0;
		rep( i , 0 , sz ) {
			if( s[i] == 'R' ) r++;
			if( s[i] == 'G' ) g++;	
			if( s[i] == 'B' ) b++;	
			if( s[i] == 'W' ) w++;
		}
		if( (r%2==0) && (g%2 == 0 ) && (b%2==0) &&(w%2==0)) cout <<"YES\n";
		else cout << "NO\n";
	}

	return 0;	
}
