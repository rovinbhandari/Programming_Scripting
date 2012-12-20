#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main () {
	int T,i,j,k,l;
	
	long M,N,a,b,c, *L;
	scanf ("%d",&T);
	
	for ( i =0 ; i <T;i++ ) {
		
		scanf( "%ld %ld", &N, &M);
		int count =0;
		double max = 0;
		L = new long[N];
		

		for ( j =0;j<N;j++){
			scanf ("%ld", &L[j]);
		}
		
		for (k = 0;k<M;k++) {
			scanf ("%ld %ld %ld", &a, &b, &c);
			double temp = (sqrt (a*a +b*b + c*c));
			if ( max < temp) {
				 max = temp;
			}
		}

		for (l =0;l<N;l++) {
			if (L[l] <= max) {
				count++;
			}
		}
		printf ( "%d\n",count);
		
	}
	return 0;
}
