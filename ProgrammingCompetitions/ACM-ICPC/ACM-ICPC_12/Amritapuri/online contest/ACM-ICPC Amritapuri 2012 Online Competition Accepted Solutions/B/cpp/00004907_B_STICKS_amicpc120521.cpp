#include<iostream>
#include<stdio.h>


int stick[1000000];
int main()
{
	int t;

	scanf("%d",&t);
	while(t--)
	{
		int N,i,M,L,B,H;

		scanf("%d %d",&N,&M);
		for(i = 1;i <=N;i++)
			scanf("%d",&stick[i]);
		

		long long max = 0;
		for(i = 1;i <=M;i++)
		{
			scanf("%d %d %d",&L,&B,&H);
			long long diag = (long long)L*L + (long long)(B*B) + (long long)(H*H);
			if(diag > max) max = diag;
		}

		int cnt = 0;
		for(i = 1;i <=N;i++)
			if((long long)stick[i]*stick[i] <= max)cnt++;
		
				printf("%d\n",cnt);
		
	}

	return 0;
}