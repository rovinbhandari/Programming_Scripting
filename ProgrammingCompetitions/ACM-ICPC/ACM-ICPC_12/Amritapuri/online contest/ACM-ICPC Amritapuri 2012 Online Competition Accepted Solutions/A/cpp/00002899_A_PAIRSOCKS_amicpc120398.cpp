#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	int t,a,b,c,d;
	cin >> t;
	while(t--) {
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		string s;
		cin >> s;
		for(int i = 0;i < s.length();i++) {
			if(s[i] == 'R')
				a++;
			else if(s[i] == 'G')
				b++;
			else if(s[i] == 'B')
				c++;
			else if(s[i] == 'W')
				d++;
		}
		if(a%2 == 0 && b%2 == 0 && c%2 == 0 && d%2 == 0)
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
	return 0;
}
