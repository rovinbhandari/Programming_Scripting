#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y)	(x) > (y) ? (x) : (y)

int* a, * mem;
int n, N;

int maxtraversalsum(int i, int j)
{
	if(mem[i])
		return mem[i];
	int sum = a[i];
	if(j < n)
		sum += MAX(maxtraversalsum(i + j, j + 1),
				maxtraversalsum(i + j + 1, j + 1));
	mem[i] = sum;
	return sum;
}

int main(void)
{
	int t, i;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		a = (int*) malloc((N = (n * (n + 1)) / 2 + 1) * sizeof(int));
		a[0] = 0;
		mem = (int*) calloc(N, sizeof(int));
		for(i = 1; i < N; i++)
			scanf("%d", &(a[i]));
		printf("%d\n", maxtraversalsum(1, 1));
		free(a);
		free(mem);
	}
	return 0;
}

