#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int i, j, n, f , c;
	char t;
	string s;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s;
		sort(s.begin(), s.end());
		f = 0;
		for (j = 0; s[j] != '\0'; j++) {
			c = 0;
			t = s[j];
			while (t == s[j] && s[j] != '\0') {
				c = c + 1;
				j = j + 1;
			}
			if (c % 2 != 0) {
				f = 1;
				break;
			}
			else {
				j = j -1;
			}
		}
		if (f == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
