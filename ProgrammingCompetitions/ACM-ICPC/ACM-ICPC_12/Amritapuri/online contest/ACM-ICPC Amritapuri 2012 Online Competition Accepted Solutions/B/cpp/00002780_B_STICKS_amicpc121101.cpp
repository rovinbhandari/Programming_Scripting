#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;
ll L[100009];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N,M;
		scanf("%d%d", &N, &M);
		for(int i=0; i<N; i++) scanf("%lld", &L[i]);
		ll Max=0,a,b,c,val;
		for(int i=0; i<M; i++) {
			scanf("%lld%lld%lld", &a, &b, &c);
			val = a*a + b*b + c*c;
			if(val > Max) Max=val;
		}
		int ans = 0;
		for(int i=0; i<N; i++) {
			if((L[i]*L[i])<=Max) ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}