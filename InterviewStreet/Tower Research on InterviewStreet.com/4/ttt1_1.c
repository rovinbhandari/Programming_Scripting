#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF	1000001		// TODO: increase it later on.

int* input = NULL;
int* apspl = NULL;	// apspl : all-pair shortest path lengths
unsigned int n = 0, m = 0;

inline int get(int* arr, unsigned int x, unsigned int y)
{
	return arr[x * n + y];
}

inline void set(int* arr, unsigned int x, unsigned int y, int v)
{
	arr[x * n + y] = v;
}

inline void setsmaller(int* arr, unsigned int x, unsigned int y, int v)
{
	if(v < get(arr, x, y))
		arr[x * n + y] = v;
}

void print2D(int* arr)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("%d\t", get(arr, i, j));
		printf("\n");
	}
	printf("\n");
}

void init(void)
{
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(i == j)
				set(input, i, j, 0);
			else
				set(input, i, j, INF);
}

void FloydWarshall(void)
{
	int i, j, k;
	for(k = 0; k < n; k++)
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				if(		get(apspl, i, k) != INF
					&&	get(apspl, k, j) != INF
				  )
				  	setsmaller(apspl, i, j, get(apspl, i, k) + get(apspl, k, j));
}

void servequeries(int q)
{
	int a, b;
	while(q--)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		printf("%d\n", get(apspl, a, b));
	}
}

int main(void)
{
	int t, a, b, w, q;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		input = malloc(sizeof(int) * n * n);
		apspl = malloc(sizeof(int) * n * n);
		init();
		print2D(input);
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d", &a);
			scanf("%d", &b);
			scanf("%d", &w);
			setsmaller(input, a, b, w);
		}
		memcpy(apspl, input, sizeof(int) * n * n);
		print2D(input);
		print2D(apspl);
		FloydWarshall();
		print2D(input);
		print2D(apspl);
		scanf("%d", &q);
		servequeries(q);
		printf("\n=========\n");
	}
}

