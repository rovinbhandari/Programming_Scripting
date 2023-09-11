#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

int main(){

	long int t,sticks,box,i,k;
	long int count=0;
	long int L[50001],A[50001],B[50001],C[50001];
		scanf("%ld",&t);

	for(k=0;k<t;k++){

	scanf("%ld",&sticks);

	scanf("%ld",&box);


	for(i=0;i<sticks;i++){
		scanf("%ld",&L[i]);
	}

	for(i=0;i<box;i++){
		scanf("%d %d %d",&A[i],&B[i],&C[i]);
	}

	int max=0,tmp;
	for(i=0;i<box;i++){
		tmp=sqrt(A[i]*A[i]+B[i]*B[i]+C[i]*C[i]);
		if(tmp>max)
			max=tmp;
	}
	count=0;
	for(i=0;i<sticks;i++){
		if(L[i]<=max)
			count++;
	}
	printf("%d\n",count);

	}
	return 0;
}
