#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<algorithm>
#include<set>
#include<math.h>
#include<map>

#define FOR(i ,  n) \
	for(i = 0; i < n; i++)
#define FORI(i ,startForIndex , endForIndex) \
	for(i = startForIndex ;i < endForIndex; i++)
#define FORD(i ,startForIndex , endForIndex) \
	for(i = startForIndex - 1;i >= endForIndex; i--)
#define tr( container , it) \
	for( typeof(container.begin()) it = container.begin() ; it != container.end() ; it++ ) 
#define print1(ar) \
	for( typeof(ar.begin()) it = ar.begin() ; it != ar.end(); it++){\
		cout << * it << " " ;\
	}printf("\n") ;
#define print2(ar)\
	for( typeof(ar.begin()) it = ar.begin() ; it != ar.end(); it++){\
		for(typeof(it->begin()) itt = it->begin() ; itt !=  it->end() ; itt++ ){\
			cout << * itt << " " ;\
		}printf("\n") ;\
	}printf("\n");
#define ALL(ar)\
	ar.begin() , ar.end()
#define PB push_back
#define LL long long int 
#define VI	vector < int > 
#define VVI 	vector < VI >  
#define VVVI 	vector < VVI > 
#define VS	vector < string >
#define VL	vector < LL > 
#define VVL 	vector < VL >
#define V(i) 	vector < i >
#define VV(i) 	vector < vector < node > > 
#define p(var)	cout << #var << " = " << var << endl ;

using namespace std ;
int main(){
	LL i , t , j , tmp, n, m , k , count , flag, ind1 ,ind2 , a , b, ans, low ,high , mid, l , h ;
	cin >> t ;
	while(t--) {
		cin >> n >>  l >> h ;
		VL ar ( n ) ;
		FOR(i , n) {
			scanf("%lld", &ar[i] ) ;
		}
		sort(ALL(ar)) ;
//		print1(ar) ;
		ans = 0 ;
		FOR(i , n ) {
			FORI(j , i + 1 , n) {
				k = l - ar[i] - ar[j] ; 
				a = j + 1 ; b = n -1 ; 
				while( a < b ) {
					mid = (a + b ) /2 ;
		//			printf("loop1 with a = %lld , b = %lld, mid = %lld , ar[mid] = %lld\n", a, b, mid, ar[mid]) ;
					if (ar[mid] < k ) {
						a = mid + 1 ; 
					}
					else {
						b = mid ;
					}
				}
				if (ar[a] < k ) {
					continue ;
				}
				ind1= a ;
//				p(ind1) ;
				
				k = h - ar[i] - ar[j] ;
				a = j + 1 ; b = n -1 ; 
				while( a < b ) {
					mid = (a + b + 1) /2 ;
					if (ar[mid] <= k ) {
						a = mid  ; 
					}
					else {
						b = mid -1 ;
					}
				}
				if ( ar[a] > k ) {
					continue ;
				}
				ind2 = a ;
//				p ( ind2) ;

				count = ind2 - ind1 + 1  ; 
				if ( i >= ind1 and i <= ind2 ) {
					count-- ;
				}
				if ( j >= ind1 and j <= ind2 ) {
					count-- ;
				}
				if( count < 1 ) {
					continue ; 
				}
				ans += count ;
//				printf("tmp = %lld at i = %lld and j = %lld\n", tmp ,i , j) ;
			}
		}
		cout << ans << endl ;
	}






}
