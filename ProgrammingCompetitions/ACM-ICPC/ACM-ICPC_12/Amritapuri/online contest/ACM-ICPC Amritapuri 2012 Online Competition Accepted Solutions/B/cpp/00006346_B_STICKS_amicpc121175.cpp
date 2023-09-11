#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int main() {
	int T,i,j,k,N,M,t;
	long long int l,b,h,di,max,count,temp;
	scanf("%d",&T);
	for(i=0; i<T; i++) {
		max=count=0;
		scanf("%d%d",&N, &M);
		vector<int> len(N,0);
		for(j=0; j<N; j++) {
			scanf("%d",&t);
			len[j]=t;
		}
		for(j=0; j<M; j++) {
			scanf("%lld%lld%lld",&l,&b,&h);
			temp=(l*l)+(b*b)+(h*h);
			di=(long long int)sqrt((double)temp);
			if(di>=max) max=di;
		}
		for(j=0; j<N; j++) {
			if(len[j]<=max) count++;
		}
		printf("%lld\n",count);
	}
	return 0;
}
