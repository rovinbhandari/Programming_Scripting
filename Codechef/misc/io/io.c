#include <stdio.h>

int nothing(int x)
{
	return x;
}

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		printf("%d\n", nothing(n));
	}
	return 0;
}

