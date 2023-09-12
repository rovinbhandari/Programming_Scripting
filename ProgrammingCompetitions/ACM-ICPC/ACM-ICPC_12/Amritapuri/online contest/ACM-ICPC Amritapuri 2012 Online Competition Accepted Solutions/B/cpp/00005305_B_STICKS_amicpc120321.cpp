#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	int t;
	int m, n;
	int arr[50050];
	double diag;
	int count = 0;
	int a, b, c;

	scanf("%d", &t);
	while (t) {
		count = 0;
		diag = 0;
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			if (sqrt(a * a * 1LL + b * b * 1LL + c * c * 1LL)
			    >= diag) {
				diag =
				    sqrt(a * a * 1LL + b * b * 1LL +
					 c * c * 1LL);
			}
		}

		for (int i = 0; i < n; i++) {
			if (diag >= arr[i]) {
				count++;
			}
		}
		printf("%d\n", count);
		t--;
	}
	return 0;
}
