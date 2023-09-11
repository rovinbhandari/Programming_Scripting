#include <stdio.h>

int y;

int max$(int x)
{
	if(x == 0)
		return 0;
	else
	{
		y = max$(x >> 2) + max$(x / 3) + max$(x >> 1);
		return ((x > y) ? x : y);
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) > 0)
		printf("%d\n", max$(n));
	return 0;
}
