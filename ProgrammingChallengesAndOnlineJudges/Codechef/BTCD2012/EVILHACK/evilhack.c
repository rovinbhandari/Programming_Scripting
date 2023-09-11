#include <stdio.h>

int main(void)
{
	int t, x, y;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &x);
		scanf("%d", &y);
		printf("%d\n", x && y ? x / 2 + y / 2 + 1 : 0);
	}
	return 0;
}

