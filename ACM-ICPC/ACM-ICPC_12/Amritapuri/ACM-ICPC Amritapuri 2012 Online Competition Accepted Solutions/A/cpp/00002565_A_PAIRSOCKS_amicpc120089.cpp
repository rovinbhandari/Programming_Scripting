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
	int i , t , j , tmp, n, m , k , count , flag;
	cin >> t ;
	string s; 
	while(t--) {
		cin >> s ;
		VI ar (4 , 0) ;
		FOR( i , s.size()) {
			if ( s[i] == 'R') {
				ar[0]++ ;
			}
			else if( s[i] == 'G'){
				ar[1]++ ;
			}
			else if( s[i] == 'B'){
				ar[2]++ ;
			}
			else if( s[i] == 'W'){
				ar[3]++ ;
			}
		}
		flag = 0 ;
		FOR(i , 4) {
			if ( ar[i] % 2 == 1 ) {
				flag = 1 ;
				break;
			}
		}
		if ( flag == 0) {
			cout << "YES\n" ;
		}
		else {
			cout << "NO\n" ;
		}
	}



}
