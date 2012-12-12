#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int t;
	cin >> t;
	int N,M;
	while(t--){
		scanf("%d%d",&N,&M);
		vector<long long int> L(N,0);
		long long val=0;
		for(int i=0;i<N;i++){
			scanf("%lld",&val);
			L[i]=val*val;
		}
		int a,b,c;
		long long max=0;
		for(int i=0;i<M;i++){
			scanf("%d%d%d",&a,&b,&c);
			val = (long long )a*a+b*b+c*c;
			if(max<val) max=val;
		}
		int count=0;
		for(int i=0;i<N;i++){
			if(max>=L[i])count++;
		}
		cout<<count<<endl;
	}
	return 0;
}