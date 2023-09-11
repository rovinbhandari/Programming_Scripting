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
	int ans;
	int n, L, H, *l;
	int flag;
	cin >> t;
	int a[1100];
	while(t--) {
		ans=0;
		cin >> n >> L >> H;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		flag=1;
		for(int i = 0; i < n && flag; i++) {
			for(int j = i+1; j < n && flag; j++) {
				l = lower_bound(a+j+1, a+n, L-a[i]-a[j]);
			//	l=a+j+1;
			//	cout << a[0] << " " << *l << endl;
				for(; l < a + n; l++) {
				//	cout << *l << " " ;
					if((a[i]+a[j]+(*l)) >= L && (a[i]+a[j]+(*l)) <= H) {
						ans++;
					}
					else break;
				}
				//cout << endl;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
