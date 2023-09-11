#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// it is both necessary and sufficient to check that the given string \
is a palindrome.

int main(void)
{
	int t;
	cin >> t;
	string s, r;
	while(t--)
	{
		cin >> s;
		r = string(s);
		reverse(s.begin(), s.end());
		cout << (s == r ? "YES" : "NO")
			 << endl;
	}
	return 0;
}
