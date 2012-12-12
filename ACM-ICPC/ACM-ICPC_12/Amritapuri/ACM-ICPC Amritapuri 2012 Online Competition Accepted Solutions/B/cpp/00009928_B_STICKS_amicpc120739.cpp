/*
 * BICPC.cpp
 *
 *  Created on: Nov 4, 2012
 *      Author: akashmamtani
 */

#include <stdio.h>
#include <cmath>

int main()
{
	int tests=0;
	scanf("%d",&tests);
	long long len[50001];
	while(tests--)
	{
		//memset(len,0,sizeof(len));
		int N,M;
		scanf("%d %d",&N,&M);
		for(long long i=0;i<N;i++)
		{
			scanf("%lld",&len[i]);
		}
		long long l,b,h;
		long long d1=0,d2=0,d3=0,max;
		long long count=0;

		while(M--)
		{
			scanf("%lld %lld %lld",&l,&b,&h);
			max=sqrt(pow(l,2)+pow(b,2)+pow(h,2));
			if(max>d1)
				d1=max;
		}
		for(long long i=0;i<N;i++)
		{
			if(len[i]<=d1)
				++count;
		}
		printf("%lld\n",count);
	}
	return 0;
}

