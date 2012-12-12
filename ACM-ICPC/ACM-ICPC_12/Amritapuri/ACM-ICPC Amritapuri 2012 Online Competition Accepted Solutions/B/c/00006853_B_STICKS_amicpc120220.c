#include<stdio.h>
#include<stdlib.h>
int comp (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int sqrt1( double num )
{
	if(num==0)
		return 0;
	double estimation = 1.0;
	int i;

	for( i = 0; i < 40; i++)
	{
		estimation = (estimation + ( num / estimation )) / 2.0;
	}
	
	return (int)estimation;
}
int main()
{
	int T,N,M,*L,A,B,C,i;
	long long int max,temp,sq;
	scanf("%d",&T);
	while(T>0)
	{
		scanf("%d %d",&N,&M);
		L=(int*)malloc(N*sizeof(int));
		max=0;
		for(i=0;i<N;i++)
		{
			scanf("%d",&L[i]);
		}
		for(i=0;i<M;i++)
		{
			scanf("%d %d %d",&A,&B,&C);
			if((temp=((long long)A*A)+((long long)B*B)+((long long)C*C))>max)
				max=temp;
		}

		sq=(int)sqrt1(max);
		qsort(L,N,sizeof(int),comp);
		for(i=0;i<N&&L[i]<=sq;i++);
		printf("%d\n",i);
		T--;
		free(L);
	}
	return 0;
}
