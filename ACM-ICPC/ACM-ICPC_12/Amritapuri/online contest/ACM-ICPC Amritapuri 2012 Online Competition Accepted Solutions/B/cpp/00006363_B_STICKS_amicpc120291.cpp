#include<stdio.h>
#include<math.h>
int main()
{
	int T;
	long int N, M, L[50001], a, b, c, i , j, count[11],ans,k=0;
	double temp, max=0;
	scanf("%d",&T);
	while(T--)
	{
		max=0;
		count[k] = 0;
		scanf("%ld %ld", &N, &M);
		for(i=0;i<N;i++)
		{
			scanf("%ld",&L[i]);
		}
		for(i=0;i<M;i++)
		{
			scanf("%ld %ld %ld",&a,&b,&c);
			ans=(a*a)+(b*b)+(c*c);
			temp = sqrt(ans);
			if(temp>max)
				max=temp;
		}
		for(i=0;i<N;i++)
		{
			if(L[i]<=max)
				count[k]++;
		}
		k++;
	}
	for(i=0;i<k;i++)
	{
		printf("%ld\n",count[i]);
	}
	return 0;
}
