#include <stdio.h>
#include <math.h>

int main(void)
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		printf("%d\n", 1 + 2 * (n - (1 << ((int) floor(log2(n))))));
	}
	return 0;
}

