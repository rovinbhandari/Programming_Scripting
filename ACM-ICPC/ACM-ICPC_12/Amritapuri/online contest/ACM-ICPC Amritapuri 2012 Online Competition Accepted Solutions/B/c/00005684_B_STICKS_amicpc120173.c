#include<stdio.h>

long long sticks[50001];

int main()
{
	int T, N, M;

	long long  l, b, h;

	long long max = -1, diag;
	int count, diagCount, i;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &N, &M);
		count=0;
		diagCount = 0;
		max=-1;

		for(i = 0; i < N; i++)
		{
			scanf("%lld", &sticks[i]);
		}

		for(i = 0; i < M; i++)
		{
			scanf("%lld%lld%lld", &l, &b, &h);

			diag = l*l + b*b + h*h;

			if(max == diag)
			{
				diagCount++;
			}
			else if(max < diag)
			{
				max = diag;
				diagCount = 1;
			}
		}

		for(i = 0; i < N; i++)
		{
			if(sticks[i] * sticks[i] == max && diagCount > 0)
			{
				count++;
				diagCount--;
			}
			else if(sticks[i] * sticks[i] < max)
				count++;
		}

		printf("%d\n", count);
	}
	return 0;
}
