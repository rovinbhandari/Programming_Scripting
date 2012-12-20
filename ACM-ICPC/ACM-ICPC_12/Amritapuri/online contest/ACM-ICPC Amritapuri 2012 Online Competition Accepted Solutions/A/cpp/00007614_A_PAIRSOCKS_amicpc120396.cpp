#include <iostream>
#include <algorithm>
#include<cstdio>
#include<cctype>
using namespace std;
int main()
{
	int i, j, n, flag , c;
	char t;
	string str;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> str;
		sort(str.begin(), str.end());
		flag = 0;
		for (j = 0; str[j] != '\0'; j++) {
			c = 0;
			t = str[j];
			while (t == str[j] && str[j] != '\0') {
				c = c + 1;
				j = j + 1;
			}
			if (c % 2 != 0) {
				flag = 1;
				break;
			}
			else {
				j = j -1;
			}
		}
		if (flag == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
