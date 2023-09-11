#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <utility>
#include <cctype>
#include <list>
#include <climits>
#include <signal.h>
#include <ctime>
#include <map>
#include <set>

using namespace std;

#define ll long long int
int a[1000000];
double diag[1000000];
    	ll x[1000000], y[1000000], z[1000000];

int main(){

	ll i, j, k, ct=0, m, n, t, l,r;

	int ans = 0;
	
	cin >> t;
	
	for( i = 0; i < t; i++ ) {
		ans = 0;
		cin >> n >> m;

		for(j = 0; j < n; j++){
			cin >> a[j];
		}

		for(j = 0; j < m; j++){
			cin >> x[j] >> y[j] >> z[j];
			diag[j] = sqrt ( double(x[j]*x[j] + y[j]*y[j] + z[j]*z[j]) );
		}

		

		sort(diag, diag+m);
		for(j = 0; j < n; j++){

			if( fabs( diag[m-1] - double( a[j] ) )  < 0.0000000001 || double( a[j] ) < diag[m-1] ) {
				ans++;
			}
	//		if (  flg == 1) { 
	//			ans++;
	//		}
		}

		cout << ans << endl;
	}

	return 0;
}
