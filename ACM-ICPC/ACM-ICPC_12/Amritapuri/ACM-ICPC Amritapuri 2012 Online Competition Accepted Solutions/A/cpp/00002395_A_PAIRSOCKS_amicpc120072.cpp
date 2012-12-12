#include<iostream>
#include<list>
#include<climits>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<cstdio>
using namespace std;
int main() {
	int t;
	cin >> t;
	string s;
	int r, g, b, w;
	while(t--) {
		cin >> s;
		r=g=b=w=0;
		for(int i =0 ; i < (int) s.size(); i++) {
			if(s[i] == 'R') r++;
			else if(s[i] == 'G') g++;
			else if(s[i] == 'B') b++;
			else if(s[i] == 'W') w++;
		}
		if(r%2==0 && g%2==0 && b%2==0 && w%2==0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
