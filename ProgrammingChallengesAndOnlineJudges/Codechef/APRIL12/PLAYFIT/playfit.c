#include <stdio.h>

#define MAX(a, b)	(((a) > (b)) ? (a) : (b))

int n;

int calculatediff(int max, int min)
{
	int g, diff;
	if(n)
	{
		scanf("%d", &g);
		n--;
		if(g > max)
			return calculatediff(g, min);
		else if(g < min)
		{
			diff = calculatediff(g, g);
			return MAX(max - min, diff);
		}
		else
			return calculatediff(max, min);
	}
	else
		return max - min;
}

int main(void)
{
	int t, g, maxdiff;
	scanf("%d", &t);
	while(t--)
	{
		maxdiff = 0;
		scanf("%d", &n);
		if(n == 1)
			scanf("%d", &g);
		if(n > 1)
		{
			scanf("%d", &g);
			n--;
			maxdiff = calculatediff(g, g);
		}
		if(maxdiff > 0)
			printf("%d\n", maxdiff);
		else
			printf("UNFIT\n");
	}
	return 0;
}

