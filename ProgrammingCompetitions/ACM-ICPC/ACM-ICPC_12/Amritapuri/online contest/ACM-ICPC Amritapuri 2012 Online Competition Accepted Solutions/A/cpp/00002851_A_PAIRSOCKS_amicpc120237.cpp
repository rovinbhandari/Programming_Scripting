#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>

using namespace std;


int main() {

	int t;
	cin >> t;
	while(t--) {
		map<char,int> m;
		string s;
		cin >> s;
		for(int i=0;i<s.size();i++)
			m[s[i]]++;
		bool flag = true;
		for(map<char,int>::iterator it=m.begin(); it!=m.end(); it++)
			if((it->second %2) != 0)
				flag = false;
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
