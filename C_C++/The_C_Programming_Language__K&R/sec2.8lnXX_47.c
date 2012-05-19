#include <stdio.h>

int main(void)
{
	int a[20] = {0};
	int i;
	
	i = 10;
	a[0] = 1 + i++;
	printf("%d\n", i);

	i = 10;
	a[i] = 1 + i++;
	printf("%d\n", i);

	for(i = 0; i < 20; i++)
		printf("%d\t%d\n", i, a[i]);
	
	return 0;
}

