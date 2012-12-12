#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int t;
	map < char, int >m;
	cin >> t;
	string str;
	while (t) {
		cin >> str;
		m.clear();
		for (int i = 0; i < str.size(); i++) {
			m[str[i]]++;
		}
		if (m['R'] % 2 == 0 && m['B'] % 2 == 0 && m['W'] % 2 == 0
		    && m['G'] % 2 == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

		t--;
	}
	return 0;
}
