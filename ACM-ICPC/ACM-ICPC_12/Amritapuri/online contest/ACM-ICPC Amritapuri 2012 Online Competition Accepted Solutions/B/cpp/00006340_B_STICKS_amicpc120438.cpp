#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
	long long t;
	cin>>t;
	long long n,m;
	long long stick[50000];
	long long A[50000];
	long long B[50000];
	long long C[50000];
	
	while(t--){
		cin>>n>>m;
		long long maxstick = 0;
		for (long long i = 0; i < n; ++i)
		{
			scanf("%lld",&(stick[i]));	
		}
		for (long long i = 0; i < m; ++i)
		{
			scanf("%lld%lld%lld",&(A[i]),&(B[i]),&(C[i]));
			long long m = A[i]*A[i] + B[i]*B[i] + C[i]*C[i];
			if(maxstick < m) maxstick = m;
		}

		long long count  = 0;
		for (long long i = 0; i < n; ++i)
		{
			if((stick[i]*stick[i]) <= maxstick) count++; 
		}
		cout<<count<<endl;
	}
}