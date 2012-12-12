#include <iostream>
#include <algorithm>

using namespace std;



int main() {
	int T; 
	cin >> T;

	int a[1000000];
	int n, l, h;

	int sum, count; int *lb, *ub;
	while (T--) {
		cin >> n >> l >> h;

		for (int i=0; i< n; i++)
			cin >> a[i];

		sort(a, a+n);

		// fucking optimisations

		for (int i=n-1; i>=0; i--) {
			if (a[i] + a[0] < h) {
				n = i+1;
				break;
			}
		}


		/////////////////////////////////////////

		sum = 0; count = 0;
		for (int i=0; i<n-2; i++) {
			for (int j=i+1; j<n-1; j++) {
				sum = a[i] + a[j];
				lb = lower_bound(a+j+1, a+n, l-sum);
				ub = upper_bound(a+j+1, a+n, h-sum);

				if (*lb < l-sum) ++lb;
				count += ub - lb;
			}	
		}

		cout << count << endl;
	}

	return 0;
}
