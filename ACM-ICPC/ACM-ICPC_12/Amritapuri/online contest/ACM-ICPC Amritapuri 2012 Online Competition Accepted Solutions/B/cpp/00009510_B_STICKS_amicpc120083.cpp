// #include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int main() {
	int T; 
	// cin >> T;
	scanf("%d", &T);

	long long rods[50500];
	long long dgs[50500];

	char temp;
	int n, m; long long a, b, c; int count;
	for (int i=0; i<T; i++) {
		//cin >> n >> m;
		scanf("%d", &n);
		scanf("%d", &m);

		for (int j=0; j<n; j++) {
			// cin >> rods[j];
			scanf("%lld", &rods[j]);
			rods[j] *= rods[j];
		}
		
		for (int j=0; j<m; j++) {
			// cin >> a >> b >> c;
			scanf("%lld %lld %lld", &a, &b, &c);
			dgs[j] = a*a + b*b + c*c;
		}

		////////////////////////////////////////////////////////////////////////////////////////
		sort(rods, rods + n);
		sort(dgs, dgs + m);

		count = 0;
		for (int b=0; count < n && b<m; b++) {
			while (count < n && rods[count] <= dgs[b])
				++count;
		}

	//	cout << count << endl;
		printf("%d\n", count);
	}


	return 0;
}
