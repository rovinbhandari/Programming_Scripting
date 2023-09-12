#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	int n,m;
	double A,B,C;
	double L[50005];
	int i;
	double sqt;
	double max;
	int cnt = 0;
	while(T--){
		max = -1;
		cnt = 0;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%lf",&L[i]);

		for(i=0;i<m;i++){
			scanf("%lf%lf%lf",&A,&B,&C);
			sqt = sqrt(A*A+B*B+C*C);
			if(sqt > max)
				max = sqt;
		}
		for(i=0;i<n;i++)
			if(max >= L[i])
				cnt++;
		printf("%d\n",cnt);
		
	}

	return 0;
}
