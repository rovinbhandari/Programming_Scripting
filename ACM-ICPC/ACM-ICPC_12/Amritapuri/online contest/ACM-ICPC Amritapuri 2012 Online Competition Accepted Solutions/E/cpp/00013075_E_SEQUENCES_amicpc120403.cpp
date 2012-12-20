/*************
	Team - ThePrestige
	Damodar Prasad Meena Is Captain
****************/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

#define rep(i,a,b) for(typeof(a) i=(a);i<(b);i++)
#define ll long long int
#define ii pair<int,int>
#define gi(x) scanf("%d",&x)
#define Clear(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()
#define MAX 500000


int tree[9*MAX];
int a[MAX];
int zero[MAX];
int one[MAX];
void preprocess( int N ) {
	Clear( zero , 0 );Clear( one , 0 );	
	rep( i , 1 , N+1 ) { if( a[i-1] == 0 ) zero[i] = 1; else one[i] = 1;zero[i] += zero[i-1]; one[i] += one[i-1]; }
}
int totz( int l , int r ) {
	if(  l>r ) return 0;
	return (zero[r+1]-zero[l]);
}
int toto( int l , int r ) {
	if(l>r) return 0;
	return (one[r+1]-one[l]);
}
bool init( int l , int r , int nn ) {
	if( l == r ) {
		tree[nn] = 1;
		return 0;
	}
	int mid = (l+r)/2;
	init( l , mid , 2*nn );
	init( mid+1 , r , 2*nn+1 );
	tree[nn] = max( totz( l , mid )+tree[2*nn+1] , tree[2*nn]+toto( mid+1 , r ) );	
	return 0;
}
int qry( int l , int r , int a , int b , int nn ) {
	if( a > r || b < l   ) return 0;
	if( l >= a &&  r <= b ){ 
		return tree[nn];
	}
	int mid = (l+r)/2;
	int ret = 0;
	int left = qry( l , mid , a, b , 2*nn );	
	int right = qry( mid+1 , r , a , b , 2*nn+1 );
	int low = max( a , l ) , high = min( r , b );
	if( mid > b ) {
		return left;	
	}
	else if( mid <a ) {
		return right;
	} 
	else {
		ret = max( totz(low,mid)+right , left+toto(mid+1,high) );	
		return ret;
	}
	return 0;
}
int main()
{
	int T; gi(T);
	while( T-- ) {
		int N;gi(N); 
		rep( i , 0  , N ){ char ch; cin >> ch; a[i] = ch-'0'; }
		preprocess( N ); 
		if( N == 0 ) Clear( tree , 0 );
		else bool flag= init( 0 , N-1 , 1 );
		int Q; gi(Q);
		rep( i , 0 , Q ) {
			int l , r; gi(l);gi(r); l -= 1; r -= 1;			
			cout << qry( 0 , N-1 , l , r , 1 ) << "\n";
		}
	}	
	return 0;
}
