#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int bin_search(int* array, int search_this, int i, int j){
	if (j-i<=2) {
		if (array[j]<=search_this) {
			return j;
		}
		else {
			if (array[i+1]<=search_this) {
				return i+1;
			}
			if (array[i]<=search_this) {
				return i;
			}
			return 0;
		}
	}
	int mid=(i+j)/2;
	if (array[mid]<=search_this) {
		return bin_search(array, search_this, mid, j);
	}
	return bin_search(array, search_this, i, mid);
}

int main ()
{
	int no_testcases;
	scanf("%d",&no_testcases);
	
	
	
	for (int k=1; k<=no_testcases; k++) {
		int N,L,H;
		priority_queue<int,vector<int>, greater<int> > input;
		int insert_pq;
		scanf("%d", &N);
		scanf("%d", &L);
		scanf("%d", &H);	
		for (int j=0; j<N; j++) {
			scanf("%d", &insert_pq);
			input.push(insert_pq);
		}
		int array[N+1];
		for (int j=1; j<=N; j++) {
			array[j]=input.top();
			input.pop();
		}
		for (int kj=1; kj<=N; kj++) {
		}
		
		//// array contains the elements in sorted order
		
		///N will be varied in the loop
		int pos1,pos2;
		long long answer=0;
		for (int i=1; i<=N-2; i++) {
			for (int j=i+1; j<=N-1; j++) {
				
				pos1=bin_search(array, L-array[i]-array[j], j, N);  /// will return the highest index <= than this number
				pos2=bin_search(array, H-array[i]-array[j], j, N);
				if (pos2<=j) {  
					break;  
				}
				if (array[pos1]<L-array[i]-array[j]) {
					pos1++;
				}
				pos1=max(j+1, pos1);
				answer+=pos2-pos1+1;
			}
		}
		
		printf("%lld\n",answer);
	}
	
	
	return 0;
}