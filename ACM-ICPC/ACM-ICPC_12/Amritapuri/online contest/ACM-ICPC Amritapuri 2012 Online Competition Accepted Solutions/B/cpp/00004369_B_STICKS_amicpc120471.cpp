#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;

#define MAX 1000001
int main() {
	int T, N, M;
	long long nums[MAX], a,b,c, max, tmp;
	scanf("%d", &T);

	while(T--) {
		scanf("%d %d", &N, &M);
		max = 0;
		for(int i=0; i<N; i++) {
			scanf("%lld", &nums[i]);
		}

		for(int i=0; i<M; i++) {
			scanf("%lld %lld %lld", &a, &b, &c);
			tmp = a*a + b*b + c*c;
			if(tmp > max) {
				max = tmp;
			}
		}

		int ans = 0;
		for(int i=0; i<N; i++) {
			tmp = nums[i]*nums[i];
			if(tmp <= max) {
				ans++;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}