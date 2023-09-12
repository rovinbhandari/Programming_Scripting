#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	long long int T,N,M,L[1000000],count;
	long long int imax,a,b,c;
	cin>>T;
	while(T--){
		imax=0;
		count=0;
		cin>>N>>M;
		for(int i=0;i<N;i++)
			cin>>L[i];
		for(int i=0;i<M;i++){
			cin>>a>>b>>c;
			if(a*a+b*b+c*c>imax)
				imax=a*a+b*b+c*c;
		}
		for(int i=0;i<N;i++)
			if(L[i]*L[i]<=imax)
				count++;
		printf("%lld\n",count);
	}
	return 0;
}
