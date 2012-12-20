#include<stdio.h>
int main(){
	
	int t,n,m;
	int s[50000];
	//int a[50000];
	//int b[50000];
	//int c[50000];
	
	int l,b,h;
	
	//int d[50000];
	double diag,maxd,sq;
	int i,j;
	int count;
	
	scanf("%d",&t);
	
	for( ; t>0 ; t--){
		count=0;
		maxd=0;
		diag=0;

		scanf("%d",&n);
		scanf("%d",&m);
		
		//printf("\nT= %d\nN= %d\tM= %d \n",t,m,n);
		//getchar();
		for(i=0;i<n;i++){
			scanf("%d",&s[i]);
			//printf("s[%d] %d\n",i,s[i]);
		}
		
		for(j=0;j<m;j++){
			scanf("%d",&l);
			scanf("%d",&b);
			scanf("%d",&h);
			
			diag= (double)(l*l) + (double)(b*b) + (double)(h*h);
			//printf("%lf\n",diag);
			if(diag>maxd)maxd=diag;
			//printf("diag = %lld",diag);
			
		}
		
		for(i=0;i<n;i++)
		{
			sq=(double)s[i]*(double)s[i];
			//printf("sq = %lld\n",sq);
			if(sq<=maxd)count++;
		}
		printf("%d\n",count);
	}
	
			
		
}
