#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int binsrch(long long int array[], long long int left, long long int right, long long int value) {
	long long int center;
	while (left <= right) {
		center = (left+right)/2;
		if (array[center] > value) {
			right = center-1;
		}
		else if (array[center] < value) {
			left = center+1;
		}
		else {
			return center;
		}
	}
	return right;
}

int main() {
	long long int T, N,M, L[100001],a,b,c, i;
	    long long int maxSize, diag;
	scanf("%lld", &T);
	while (T--) {
		maxSize = 0;
		scanf("%lld%lld", &N, &M);
		for (i = 0; i < N; i++) {
			scanf("%lld", &L[i]);
		}
		for (i = 0; i < M; i++) {
			cin>>a>>b>>c;
			if ((diag=a*a+b*b+c*c) > maxSize) {
				maxSize = diag;
			}
		}
		maxSize = (long long int)sqrt(maxSize);
		sort(L, L+N);
		long long int index = binsrch(L, 0, N-1, maxSize);
		while (index != -1 && index+1 < N && L[index + 1] == L[index ]) {
			index++;
		}
		printf("%lld\n", index + 1);
	}
	return 0;
}
