    #include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
typedef long long ll;

int main() {
	//freopen("in.cpp", "r", stdin); freopen("out.cpp", "w", stdout);
	
	int nt; scanf("%d", &nt); while(nt--) {
		int n, L, R; scanf("%d %d %d", &n, &L, &R);
		int a[n]; REP(i,n) scanf("%d", &a[i]);
		ll ans = 0;
		sort(a,a+n);
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++) {
				
				int sum = a[i] + a[j];
				int x = L-sum, y = R-sum;
				
				int *p1 = lower_bound(a+j+1, a+n, x);
				int *p2 = upper_bound(a+j+1, a+n, y);
				
				int num_elements = p2 - p1;
				if(num_elements > 0) ans += num_elements;
				
			}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}


