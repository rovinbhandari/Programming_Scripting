#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define LLI long long int
#define VI vector<int>
#define F(i,a,n) for(int i=a; i<n; i++)
#define FACT(n,res) F(n) res *= (i+1);
#define P(a,n,res) F(i,0,n) res *= a;
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
	string s;
	cin >> s;
	map<char,int> m;
	F(i,0,s.size()) {
		m[s[i]]++;
	}
	if (m['R']%2==0 && m['G']%2==0 && m['B']%2==0 && m['W']%2==0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	}
	return 0;
}
