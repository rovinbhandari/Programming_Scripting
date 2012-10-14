#include <stdio.h>
#include <stdlib.h>

#define INF	1000000000

int* apspl = NULL;	// apspl : all-pair shortest path lengths
unsigned int n = 0, m = 0;

void init(void)
{
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(i == j)
				apspl[i * n + j] = 0;
			else
				apspl[i * n + j] = INF;
}

void FloydWarshall(void)
{
	int i, j, k;
	for(k = 0; k < n; k++)
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				if(apspl[i * n + k] + apspl[k * n + j] < apspl[i * n + j])
					apspl[i * n + j] = apspl[i * n + k] + apspl[k * n + j];
}

void servequeries(int q)
{
	int a, b;
	while(q--)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		printf("%d\n", apspl[a * n + b]);
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
			if(w < apspl[a * n + b])
				apspl[a * n + b] = w;
		}
		FloydWarshall();
		scanf("%d", &q);
		servequeries(q);
	}
}

