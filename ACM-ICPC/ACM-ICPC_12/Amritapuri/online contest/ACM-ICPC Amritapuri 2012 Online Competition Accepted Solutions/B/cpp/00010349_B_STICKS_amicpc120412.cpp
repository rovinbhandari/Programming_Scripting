#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int l[100000],s, n, m, t, maxl, maxb;
int main()
{
	cin >> t;
	while(t--) {
		cin >> n >> m;
		maxl = 0;
					
		for(int i = 0; i < n; i++){
			cin >> l[i];
			if(maxl < l[i])	maxl = l[i];
		}

		maxb = 0;

		long long int st, x,y, z;

		for(int i = 0; i < m; i++){
			cin >> x >> y >> z;
			st = (long long int)sqrt(x*x+y*y+z*z);
			if(st > maxb)	maxb = st;
		}

//		cout << endl;

		int keeda = 0;

		for(int  i =0 ;i < n; i++)
			if(l[i] <= maxb)	keeda++;
		cout << keeda << endl;
	}
	
	return 0;
}
		
		
		
