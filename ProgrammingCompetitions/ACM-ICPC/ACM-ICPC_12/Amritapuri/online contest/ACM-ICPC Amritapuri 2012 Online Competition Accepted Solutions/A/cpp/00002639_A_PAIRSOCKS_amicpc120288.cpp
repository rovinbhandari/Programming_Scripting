#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<cstring>
#include<string>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string c;
		cin >> c;
		int r = 0, g = 0, b = 0, w = 0;
		int l = c.size();
		for(int i = 0; i < l; ++i)
			if(c[i] == 'R') ++r;
			else if(c[i] == 'G') ++g;
			else if(c[i] == 'B') ++b;
			else if(c[i] == 'W') ++w;
		if(!(r & 1) && !(g & 1) && !(b & 1) && !(w & 1))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
