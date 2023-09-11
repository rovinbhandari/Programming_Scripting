#include <stdio.h>
#include <stdlib.h>

#define DBG 0
#define INF	1000000000

int* apspl = NULL;	// apspl : all-pair shortest path lengths
unsigned int n = 0, m = 0;

inline int get(unsigned int x, unsigned int y)
{
	return apspl[x * n + y];
}

inline void set(unsigned int x, unsigned int y, int v)
{
	apspl[x * n + y] = v;
}

inline void setsmaller(unsigned int x, unsigned int y, int v)
{
	if(v < get(x, y))
		apspl[x * n + y] = v;
}

void print2D()
{
	if(!DBG)
		return;
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			fprintf(stderr, "%d\t", get(i, j));
		fprintf(stderr, "\n");
	}
	fprintf(stderr, "\n");
}

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
				if(		get(i, k) != INF
					&&	get(k, j) != INF
				  )
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
		print2D();
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d", &a);
			scanf("%d", &b);
			scanf("%d", &w);
			setsmaller(a, b, w);
		}
		print2D(apspl);
		FloydWarshall();
		print2D(apspl);
		scanf("%d", &q);
		servequeries(q);
		if(DBG)
			fprintf(stderr, "\n=========\n");
	}
}

