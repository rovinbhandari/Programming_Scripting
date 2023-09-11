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
	long long int t;
	long long int n, m;
	long long int s[100000];
	long long int A;
	long long int B;
	long long int C;
	long long int ans;
	long long int Max;
	cin >> t;
	while(t--) {
		cin >> n;
		cin >> m;
		ans = 0;
		for(long long int i = 0; i < n; i++) {
			cin >> s[i];
		}
		Max = -1;
		for(long long int i=0; i < m; i++) {
			cin >> A >> B >> C;
			if(A*A+B*B+C*C > Max) {
				Max=A*A+B*B+C*C;
			}
		}
		for(long long int i = n-1; i >= 0; i--){
			if(s[i]*s[i] <= Max) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
