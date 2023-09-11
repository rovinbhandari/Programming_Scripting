#include <stdio.h>
#include <string.h>

#define MAX(x, y)	(x) > (y) ? (x) : (y)
#define NMAX		5051

int a[NMAX], mem[NMAX];
int n, N;

int maxtraversalsum(int i, int j)
{
	if(mem[i])
		return mem[i];
	int sum = a[i];
	if(j < n)
		sum += MAX(maxtraversalsum(i + j, j + 1),
				maxtraversalsum(i + j + 1, j + 1));
	return mem[i] = sum;
}

int main(void)
{
	int t, i;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		a[0] = 0;
		memset(mem, 0, (N = (n * (n + 1)) / 2 + 1) * sizeof(int));
		for(i = 1; i < N; i++)
			scanf("%d", &(a[i]));
		printf("%d\n", maxtraversalsum(1, 1));
	}
	return 0;
}

