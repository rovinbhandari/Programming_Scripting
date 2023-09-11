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
	double i , t , j , tmp, n, m , k , count , flag, a, b, c;
	int itm[3] ; ;
	cin >> t ;
	while(t--) {
//		scanf("%d%d", &n , & m) ;
		cin >> n >> m ;
		vector < double >  ar ( n)  ;
		FOR( i , n) {
//			scanf("%d", &ar[i] ) ;
			cin >> ar[i] ;
		}
		LL maxi = 0 ; 
		FOR( i , m) {
			scanf("%d%d%d", &itm[0] , &itm[1] , &itm[2] ) ;
			a = itm[0] ; b = itm[1] ; c = itm[2] ; 
			tmp = a * a + b * b + c * c ;
			tmp = sqrt ( tmp ) ;
			if( tmp > maxi ) {
				maxi = tmp ;
			}
		}
//		cout << maxi ; 
		count = 0 ;
		FOR( i ,n) {
			if ( ar[i] <= maxi ) {
				count++ ;
			}
		}
		cout << count << endl ;
	}
			


}
