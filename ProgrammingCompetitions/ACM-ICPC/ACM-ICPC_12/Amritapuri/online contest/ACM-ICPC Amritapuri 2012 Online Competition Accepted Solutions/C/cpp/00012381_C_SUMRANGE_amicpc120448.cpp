#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int V[1000][1000];

int FloorSearch( int j, int low, int high, int x)
{
	if ( x > V[j][high] )
		return high;
	if ( x < V[j][low] )
		return -1;
	while ( low <= high ) {
		int mid = (low + high)/2;
		if ( V[j][mid] == x )
			return mid;
		else if ( V[j][mid] > x ) {
			if ( mid-1 >= low && x >= V[j][mid-1] )
				return mid-1;
			else
				high = mid-1;
		} else {
			if ( mid+1 <= high && x < V[j][mid+1] )
				return mid;
			else
				low = mid+1;
		}
	}
}

int ceilSearch( int j, int low, int high, int x)
{
  int mid;    
  if(x <= V[j][low])
    return low; 
  if(x > V[j][high])
    return -1;  
	while ( low <= high ) {
  		mid = (low + high)/2; 
  		if(V[j][mid] == x)
    		return mid;
  		else if(V[j][mid] < x) {
    		if(mid + 1 <= high && x <= V[j][mid+1])
      			return mid + 1;
    		else
      			low = mid+1;
  		} else {
    		if(mid - 1 >= low && x > V[j][mid-1])
      			return mid;
    		else    
      			high = mid-1;
  		}
	}
}

int main()
{
	int T;
	scanf( "%d", &T );
	while ( T-- ) {
		int ans = 0;
		int N, L, H;
		scanf( "%d %d %d", &N, &L, &H );

		int A[N];
		int i = 0;
		while ( i < N ) {
			scanf( "%d", &A[i++] );
		}

		int Low[N], High[N];
		for ( i = 0; i < N; i++ ) {
			Low[i] = L-A[i];
			High[i] = H-A[i];
		}
		//V.clear();
		for ( i = 0; i < N-1; i++ ) {
			int k = 0;
			for ( int j = i+1; j < N; j++ ) {
				V[i][k++] = A[i]+A[j];
			}
			sort( V[i], V[i]+k );
		}

		for ( i = 0; i < N; i++ ) {
			for ( int j = i+1; j < N-1; j++ ) {
				int a = ceilSearch( j, 0, N-j-2, Low[i] );
				int b = FloorSearch( j, 0, N-j-2, High[i] );
				//cout << Low[i] << " " << High[i] << " >> " << a << " " <<b << endl;
				if ( a != -1 && b != -1 )
					ans += b-a+1;
			}
		}

		printf( "%d\n", ans );
	}

	return 0;
}
