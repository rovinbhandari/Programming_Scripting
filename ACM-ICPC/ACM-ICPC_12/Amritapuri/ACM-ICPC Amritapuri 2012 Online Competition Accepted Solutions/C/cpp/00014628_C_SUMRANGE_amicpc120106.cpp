#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int *values;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main() {
	int T, N, L, H, a[1000];
	cin >> T;
	int count = 0;
	for (int i = 0; i < T; i++) {
		cin >> N >> L >> H;
		for (int j = 0; j < N; j++) {
			cin >> a[j];
		}
		values = a;
		qsort (values, N, sizeof(int), compare);
		int tempN = N-1;
		for (int k = N-1; k >= 0; k--)
		{
			if(a[k] < H) {
				tempN = k;
				break;
			}
		}
		for (int l = 0; l <= tempN; l++) {
			for (int m = tempN; m > l; m--) {
				if(H > a[m] + a[l]){
					for (int n = l+1; n < m; n++) {
						if(L <= a[l] + a[m] + a[n]) {
							if(H >= a[l] + a[m] + a[n]){
									// cout<<a[l]<<" "<<a[m]<<" "<<a[n]<<endl;
									count ++;
							}
							else break;
						}
					}
				}
			}
		}
		cout<<count<<endl;
		count = 0;
	}
	return 0;
}