#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;


int main(){
	int tests;
	scanf("%d\n",&tests );
	long int N, M;
	double leng;
	long int l , b , h;
	double max_leng;

	while(tests--){
		max_leng = 0; 
		scanf("%ld %ld\n" , &N , &M );
		priority_queue<double> pq;
		for(long int i = 0 ; i < N ; i ++){
			cin>>leng;
			pq.push(leng);
		}

		for(long int i = 0 ; i < M ; i++){
			scanf("%ld %ld %ld\n" , &l , &b , &h);
				double x = sqrt(l*l + b*b + h*h);
				if(x > max_leng) max_leng = x;
			}
		
		
		while(pq.top() > max_leng) { if(pq.size()!=1) pq.pop(); else { pq.pop(); break;}}
		printf("%ld\n" , pq.size());
	}
	return 0;
}
