# include <iostream>

using namespace std;

int main () {
	unsigned short t, n, m, nx, mx, ix, sol;
	unsigned long long sticks[50001], tmp, diag, longdiag;
	
	cin >> t;
	while (t-- > 0) {
		cin >> n >> m;
		
		for (nx = 0; nx < n; nx++ ) {
			cin >>  tmp;
			sticks[nx] = tmp*tmp;
		}
		
		longdiag = 0;
		for (mx = 0; mx < m; mx++ ) {
			diag = 0;
		
			for (ix = 0; ix < 3; ix++ ) {
				cin >> tmp;
				diag += tmp * tmp;
			}
			
			if ( diag > longdiag )
				longdiag = diag;
		}
		
		sol = 0;
		for (nx = 0; nx < n; nx++)
			if (sticks[nx] <= longdiag) 
				sol++;
		
		cout << sol <<endl;
	}
	
	return 0;
}

