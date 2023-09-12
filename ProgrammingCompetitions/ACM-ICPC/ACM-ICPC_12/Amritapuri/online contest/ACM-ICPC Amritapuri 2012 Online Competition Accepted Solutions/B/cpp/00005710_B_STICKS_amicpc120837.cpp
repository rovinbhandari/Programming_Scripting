#include<cstdio>
#include<cmath>
int main(){
	int T,N,M,i,res;
	long long A,B,C,L[50010], mxdiag, cur, lim;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&N,&M);
		for (i=0;i<N;i++)
			scanf("%lld",&L[i]);
		mxdiag = 0;
		for (i=0;i<M;i++){
			scanf("%lld%lld%lld",&A,&B,&C);
			cur = A*A + B*B + C*C;
			if (mxdiag < cur)
				mxdiag = cur;
		}
		lim = (long long)sqrt(mxdiag);
		res = 0;
		for (i=0;i<N;i++){
			if (L[i]<=lim){
				res++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
