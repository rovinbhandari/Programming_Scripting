#include <stdio.h>

int main(){
	long long int test,n,m,l,b,c,i;
	long long int a[50005];
	long long int val,count,max;

	scanf("%lld",&test);

	while(test--){
		max=-1;
		count=0;
		scanf("%lld %lld",&n,&m);

		for(i=0;i<n;++i){
			scanf("%lld",&val);

			val*=val;
			a[i]=val;
		}

		for(i=0;i<m;++i){
			scanf("%lld %lld %lld",&l,&b,&c);

			val=(l*l)+(b*b)+(c*c);

			if(val>max)
				max=val;
		}

		for(i=0;i<n;++i){
			if(a[i]<=max)
				++count;
		}

		printf("%lld\n",count);
	}

	return 0;
}