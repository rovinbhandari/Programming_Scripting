#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int get_lower_index(int* input, int left, int right, int val) {
	int mid;
	if(input[left] >= val) {
		return left;
	} else if(input[right] < val) {
		return -1;
	}

	while(left < right) {
		mid = (left + right) / 2;
		if(input[mid] < val) {
			if(input[mid+1] < val) {
				left = mid+1;
			} else {
				return mid+1;
			}
		} else {
			if(input[mid-1] < val) {
				return mid;
			} else {
				right = mid-1;
			}
		}
	}

	return left;
}

int get_upper_index(int* input, int left, int right, int val) {
	int mid;
	if(input[right] <= val) {
		return right;
	} else if(input[left] > val) {
		return -1;
	}

	while(left < right) {
		mid = (left+right)/2;
		if(input[mid] > val) {
			if(input[mid-1] > val) {
				right = mid-1;
			} else {
				return mid-1;
			}
		} else {
			if(input[mid+1] > val) {
				return mid;
			} else {
				left = mid+1;
			}
		}
	}

	return left;
}

int main() {
	int T, N, L, H, input[1024], sum, t1, t2;
	scanf("%d", &T);

	while(T--) {
		scanf("%d %d %d", &N, &L, &H);
		for(int i=0; i<N; i++) {
			scanf("%d", &input[i]);
		}

		int ans = 0, l1, l2;
		sort(input, input+N);
		for(int i=0; i<N; i++) {
			for(int j=i+2; j<N; j++) {
				t1 = L - input[i] - input[j];
				t2 = H - input[i] - input[j];
				//Binary search for index l1 such that input[l1] >= L-input[i]-input[j]
				l1 = get_lower_index(input, i+1, j-1, t1);
				//Binary search for index l2 such that input[l2] <= H-input[i]-input[j]
				l2 = get_upper_index(input, i+1, j-1, t2);

				if(l1!=-1 && l2!=-1) {
					ans += l2-l1+1;
				}
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}




/*
Problem C: Sum Range
You are given N numbers a[1..N] and 2 other integers L and H. Count the number of tuples (i,j,k) satisfying i < j < k and L <= a[i] + a[j] + a[k] <= H.
Input (STDIN):

The first line contains the number of test cases T. T test cases follow.
The first line of each test case contains the numbers N, L and H. The next line contains N space-separated integers a[1]..a[N].
There is no blank line between test cases.
Output (STDOUT):

Output T lines, each containing the answer for the corresponding test case.
Constraints:

1 <= T <= 100
1 <= N <= 1000
1 <= L <= H <= 1000000
1 <= a[i] <= 1000000 
Sample Input:

2
4 11 14
1 2 4 8
5 5 10
3 4 1 1 4
Sample Output:

3
9
Explanation:

For the first test case, the triplets of indices (1, 2, 4), (1, 3, 4) and (2, 3, 4) have their corresponding sums as 11, 13 and 14, which fall in the desired range.
Time limit : 5s

Memory limit : 32MB
*/