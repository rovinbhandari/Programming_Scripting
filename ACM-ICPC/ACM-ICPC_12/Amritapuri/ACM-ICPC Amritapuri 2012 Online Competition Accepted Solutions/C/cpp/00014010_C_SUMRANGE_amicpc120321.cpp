#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
	int t = 0, i, j;
	char ch;
	ch = getchar_unlocked();
	while (!isdigit(ch))
		ch = getchar_unlocked();
	while (isdigit(ch)) {
		t = t * 10 + (ch - 48);
		ch = getchar_unlocked();
	}
	// scanf("%d", &t);
	while (t--) {
		int n = 0, l = 0, h = 0, x = 0;
		int v[1005];
		ch = getchar_unlocked();
		while (!isdigit(ch))
			ch = getchar_unlocked();
		while (isdigit(ch)) {
			n = n * 10 + (ch - 48);
			ch = getchar_unlocked();
		}
		ch = getchar_unlocked();
		while (!isdigit(ch))
			ch = getchar_unlocked();
		while (isdigit(ch)) {
			l = l * 10 + (ch - 48);
			ch = getchar_unlocked();
		}
		ch = getchar_unlocked();
		while (!isdigit(ch))
			ch = getchar_unlocked();
		while (isdigit(ch)) {
			h = h * 10 + (ch - 48);
			ch = getchar_unlocked();
		}
		// scanf("%d %d %d", &n, &l, &h);
		for (i = 0; i < n; ++i) {
			v[i] = 0;
			ch = getchar_unlocked();
			while (!isdigit(ch))
				ch = getchar_unlocked();
			while (isdigit(ch)) {
				v[i] = v[i] * 10 + (ch - 48);
				ch = getchar_unlocked();
			}
			// scanf("%d", &x);
		}
		sort(v, v + n);
		int size = n;
		long long int cnt = 0;
		for (i = 0; i < size; ++i) {
			if (v[i] > h)
				continue;
			for (j = i + 1; j < size; ++j) {
				// cout << i << " " << j <<  " = ";
				if (v[i] + v[j] > h)
					continue;
				int l_rem = l - v[i] - v[j];
				int h_rem = h - v[i] - v[j];
				// cout << l_rem << " " << h_rem << endl;
				int *low = lower_bound(v, v + n, l_rem);
				int *high = upper_bound(v, v + n, h_rem);
				int l_index = int (low - v);
				int h_index = int (high - v);
				// if ( l_index >= j )
				// cout << l_index << " " << h_index << endl;
				if (l_index > j) {
					// cout << "add : " << h_index-l_index << endl;
					cnt += h_index - l_index;
				} else if (h_index <= j);
				else {
					// cout << "add : " << h_index - j - 1 << endl;
					cnt += h_index - j - 1;
				}
			}
		}
		printf("%lld\n", cnt);
	}
	return 0;
}
