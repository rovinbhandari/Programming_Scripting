#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int T,*ans=NULL;
	int j=0;
	scanf("%d",&T);
	ans = malloc ( T*sizeof(int) );
	
	while(j<T){
		ans[j]=0;
		int n,m;
		scanf("%d %d",&n,&m);
		long long *len=NULL;
		int **dime=NULL;
		long long maxlen=0;
		long long tmp=0;
		int i=0;
		
		len = (long long*) malloc ( n*sizeof(long long) );
		dime = (int**) malloc ( m*sizeof(int*) );
		
		for(i=0;i<m;i++)
			dime[i] = malloc ( 3*sizeof(int) );
		for(i=0;i<n;i++)
			scanf("%lld",&len[i]);
		for(i=0;i<m;i++){
			
			scanf("%d %d %d",&dime[i][0],&dime[i][1],&dime[i][2]);
			tmp = (long long) (dime[i][0]*dime[i][0]) + (dime[i][1]*dime[i][1]) + (dime[i][2]*dime[i][2]) ;
			if(tmp >= maxlen)
				maxlen = tmp;
		}
		
		for(i=0;i<n;i++){
			if((len[i]*len[i]) <= maxlen)
				ans[j]++;
		      }
		j++;
		free(len);
		free(dime);
	}
	
	for(j=0;j<T;j++)
		printf("%d\n",ans[j]);
	free(ans);
	return 0;
}
