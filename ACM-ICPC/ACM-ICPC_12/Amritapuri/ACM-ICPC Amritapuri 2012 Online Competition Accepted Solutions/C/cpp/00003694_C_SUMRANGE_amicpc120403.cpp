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

int a[2009];
ll f( int n , int l ) {
	int ret = 0;
	rep( i , 0 , n ) {
                        int j = i+1 , k = n-1;
		while( j < k ) {
                	if( a[i]+a[j]+a[k] <= l ) { ret+= (k-j); j++; }
			else k--;
		}
	}
	return ret;
}
int main()
{
	int T; gi(T);
	while( T-- ) {
		int n , l , h; gi(n);gi(l);gi(h);
		int ans = 0;
		rep( i , 0 , n ) {
			scanf("%d" ,&a[i]);
		}
		sort( a , a+n );
		ans = f( n,h) -f( n , l-1);	
		cout << ans << "\n";
	}
	return 0;	
}
