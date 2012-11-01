#include <stdio.h>
#include <stdlib.h>

#define INF	1000000000

int* apspl = NULL;	// apspl : all-pair shortest path lengths
unsigned int n = 0, m = 0;

#define get(x, y)			apspl[x * n + y]

#define set(x, y, v)		do	\
								apspl[x * n + y] = v;	\
							while(0)

#define setsmaller(x, y, v)	do	\
								if(v < get(x, y))	\
									apspl[x * n + y] = v;	\
							while(0)

void init(void)
{
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(i == j)
				set(i, j, 0);
			else
				set(i, j, INF);
}

void FloydWarshall(void)
{
	int i, j, k;
	for(k = 0; k < n; k++)
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				setsmaller(i, j, get(i, k) + get(k, j));
}

void servequeries(int q)
{
	int a, b;
	while(q--)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		printf("%d\n", get(a, b));
	}
}

int main(void)
{
	int t, a, b, w, q;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		apspl = malloc(sizeof(int) * n * n);
		init();
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d", &a);
			scanf("%d", &b);
			scanf("%d", &w);
			setsmaller(a, b, w);
		}
		FloydWarshall();
		scanf("%d", &q);
		servequeries(q);
	}
}

