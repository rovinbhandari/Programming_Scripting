#include <stdio.h>

#define MAXN 50005

int lens[MAXN];

long long Max(long long a, long long b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	int T, N, M, l, i, count;
	long long maxD, a, b, c;
	
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &M);
		maxD = 0L;
		count = 0;
		for (i=0; i<N; i++)
			scanf("%d", &lens[i]);
		for (i=0; i<M; i++)
		{
			scanf("%lld %lld %lld", &a, &b, &c);
			maxD = Max(maxD, a*a+b*b+c*c);
		}
		
		for (i=0; i<N; i++)
			if (((long long)lens[i])*lens[i] <= maxD)
				count++;
		printf("%d\n", count);
	}
	
	return 0;
}

