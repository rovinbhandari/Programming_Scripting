#include <stdio.h>

int main(void)
{
	int t, n, k;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		scanf("%d", &k);
		printf("%s\n", (k + 1) % (1 << n) ? "OFF" : "ON");
	}
	return 0;
}

