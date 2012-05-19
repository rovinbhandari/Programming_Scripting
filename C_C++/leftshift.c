#include <stdio.h>

int main()
{
	unsigned short int x = 0;
	x = x << 1 | 1;
	printf("%d\n", x);
	x = x << 1 | 1;
	printf("%d\n", x);
	x = x << 1 | 1;
	printf("%d\n", x);
	x = x << 1 | 1;
	printf("%d\n", x);

	return 0;
}
