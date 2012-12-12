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
	LL i , t , j , tmp, n, m , k , count , flag, ind , col ;
	cin >> t ;
	while(t--) {
		cin >> n ; 
		vector < set < int >  >  ar ( n) ; 
		FOR(i , n) {
			scanf("%lld", &k ) ;
			FOR( j , k ) {
				scanf("%lld", &tmp) ;
				ar[i].insert(tmp) ;
				ar[tmp].insert( i ) ;
			}
		}
//		print2(ar) ;
		VL ck ( n, -1) ;
		count = 0 ;
		flag = 0 ;
		FOR( i , n) {
			if (ck[i] != -1 ) {
				continue ;
			}
//			p( i) ;
			queue < int > qu ;
			qu.push(i ) ;
			ck[i] = 0 ;
			while(!qu.empty()) {
				ind = qu.front() ;
				qu.pop() ;
				col = ck[ind] ; 
//				p(ind) ;
				for( typeof(ar[ind].begin()) it = ar[ind].begin() ; it != ar[ind].end(); it++){
					tmp = *it ;
	//				p( tmp ) ;
					if ( ck[tmp] == -1 ) {
						ck[tmp] = 1 -col ; 
						qu.push(tmp) ;
					}
					else {
						if ( ck[tmp] != 1 - col ) {
							flag = 1 ;
							break ;
						}
					}
				}
				if ( flag == 1) {
					break ;
				}
			}
			if ( flag == 1) {
				break ;
			}
			count++ ;
		}
//		p( count) ;
//		print1(ck) ;
		if ( flag == 1) {
			cout << "0\n" ;
			continue ;
		}
		LL ans = 1 ;
		FOR(i ,count ) {
			ans *=2 ; 
			ans %= 1000000007 ;
		}
		cout << ans << endl ;
	}


						
}
