#include<stdio.h>
#include<math.h>

int main(){
	long int i,j,k,n,m,d,t,count,max,temp;

	long int l[50500];
	scanf("%ld",&t);
	while(t--){
	    count=0;max=-1;
		scanf("%ld%ld",&n,&m);
		for(i=0;i<n;i++){scanf("%ld",&l[i]);l[i]=l[i]*l[i];}
		for(i=0;i<m;i++){scanf("%ld%ld%ld",&j,&k,&d);temp=pow(j,2)+pow(k,2)+pow(d,2);if(max<temp)max=temp;}

		for(i=0;i<n;i++){

                if(l[i]<=max)count++;

		}
		printf("%ld\n",count);
	}
	return 0;
}
