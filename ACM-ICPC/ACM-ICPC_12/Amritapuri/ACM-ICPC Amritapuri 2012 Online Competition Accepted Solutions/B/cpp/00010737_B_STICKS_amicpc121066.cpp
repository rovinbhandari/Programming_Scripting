#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	long long int i, j,t, m, n,b, d, e, count,c, s;
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> n >> m;
		long long int a[n];
		for (j = 0; j < n; j++) {
			scanf("%lld", &a[j]);
		}
		for (j = 0; j < m; j++) {
			cin >> b >> d >> e;
			s = sqrt(b * b + d * d + e * e);
			if (j == 0) {
				c = s;
			}
			if (c < s) {
				c = s;
			}
		}
		count = 0;
		for (j = 0; j < n; j++) {
			if (a[j] <= c) {
				count = count + 1;
			}
		}
		cout << count << endl;
	}
	return 0;
}
