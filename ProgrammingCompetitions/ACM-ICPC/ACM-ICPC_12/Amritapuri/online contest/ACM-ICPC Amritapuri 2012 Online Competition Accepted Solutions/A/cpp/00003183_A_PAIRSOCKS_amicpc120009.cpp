#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		string temp;
		cin >> temp;
		int r=0,b=0,g=0,w=0;
		for (string::iterator itr = temp.begin() ; itr != temp.end() ; itr++) {
			if (*itr == 'R') r++;
			else if (*itr == 'B') b++;
			else if (*itr == 'G') g++;
			else if (*itr == 'W') w++;
		}
		if (b%2 == 0 and r%2 == 0 and g%2 == 0 and w%2 == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
