#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int ceilSearch( double arr[], int low, int high, int x )
{
	int mid;
	if( (double)x <= arr[low])
    	return low; 
    if( (double)x > arr[high])
    	return -1;  

	mid = (low + high)/2; 
	if(arr[mid] == (double)x)
    	return mid;
    else if(arr[mid] < (double)x)
  	{
    	if(mid + 1 <= high && (double)x <= arr[mid+1])
      	return mid + 1;
    	else
      		return ceilSearch(arr, mid+1, high, x);
  	} 
  	else
  	{
    	if(mid - 1 >= low && (double)x > arr[mid-1])
      	return mid;
    	else    
      	return ceilSearch(arr, low, mid - 1, x);
  	}
}

int main()
{
	int T;
	cin >> T;
	while ( T-- ) {
		int N, M;
		cin >> N >> M;
		int L[N];
		long double D[M];
		int i, j;
		i = j = 0;
		while ( i < N ) {
			cin >> L[i++];
		}

		while ( j < M ) {
			double a, b, c;
			cin >> a >> b >> c;
			D[j] = (long double)sqrt( (long double)(a*a + b*b + c*c) );
			j++;
		}

		sort( L, L+N );
		sort( D, D+M );

		bool done = false;
		for ( i = N-1; i >= 0; i-- ) {
			if ( (long double)L[i] > D[M-1] )
				continue;
			else
				break;
		}

		cout << i+1 << endl;
	}

	return 0;
}