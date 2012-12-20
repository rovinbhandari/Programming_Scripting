#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
	int t;
	cin >> t;
	int n;
	int cnt,  p1, p2;
	long int *ptr = NULL;
	int i, j, k;
	long int a[1001] = {0};
	long int h, l;
	long int x, y;
	while (t--) {
		cin >> n >> l >> h;
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort (a, a+n);
		cnt = 0;
		for (i = 0; i < n-2; i++) {
			for (j = i+1; j < n-1; j++) {
				//for (k = j+1; k < n; k++) {
					//if (l - (a[i] + a[j]) <= a[k] && h - (a[i] + a[j]) >= a[k]) {
				x = l - a[i] - a[j];
				y = h - a[i] - a[j];
				k= j+1;
//				cout << "x=" << x << '\t' << "y=" << y << '\t' << "ak=" << a[k] << endl;
				if (x < a[k]) {
					p1 = k;
//					cout << "1.....\n";
//					cout << "yahan\t" << p1 << endl;
				} else if (x > a[n - 1]) {
					p1 = n - 1;
					cnt--;
//					cout << "2.....\n";
				} else {
					ptr=  lower_bound (a+k, a + n, x);
					p1 = (int)(ptr - a);
//					cout << "3.....\n";
//					cout << "here......" << x << '\t' << p1 << endl;
				}

				if (y > a[n-1]) {
					p2 = n-1;
//					cout << "4.....\n";
//					cout << "kahan " << p2 << endl;
				} else if (y < a[k]) {
					p2 = k;
					cnt--;
//					cout << "5.....\n";
				} else {
					ptr = upper_bound (a + k, a + n,y);
					p2 = (int)(ptr - a);
//					cout << "msfms\t" << p2 << endl;
					if (*ptr == a[p2])
						p2--;
//					cout << "6.....\n";

				}
//				cout << "p1 " << p1 << "\t p2 " << p2 << endl;
				cnt += p2 - p1 + 1;
			}

		}
		cout << cnt << endl;

	}
	return 0;
}