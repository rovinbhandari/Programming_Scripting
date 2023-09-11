#include <stdio.h>

int main(void)
{
	int t, g, i, n, q;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &g);
		while(g--)
		{
			scanf("%d", &i);
			scanf("%d", &n);
			scanf("%d", &q);
			printf("%d\n", i == 1 ? (q == 1 ? n / 2 : n - n / 2) : (q == 2 ? n / 2 : n - n / 2));
		}
	}
	return 0;
}

