#include <stdio.h>

#define MAX(a, b)	(((a) > (b)) ? (a) : (b))

int n;

int calculatediff(int max, int min)
{
	int diff, g;
	if(n)
	{
		scanf("%d", &g);
		n--;
		if(g > max)
			return diff = MAX(g - min, calculatediff(g, min));
		else if(g < min)
			return diff = MAX(max - min, calculatediff(g, g));
		else
			return diff = MAX(max - min, calculatediff(max, min));
	}
	else
		return MAX(diff, max - min);
}

int calculatediff2(int max, int min)
{
	int g, tempdiff;
	int temp;
	if(n)
	{
		scanf("%d", &g);
		n--;
		if(g > max)
		{
			temp = calculatediff2(g, min);
			//fprintf(stderr, "\t> temp = %d\n", temp);
			return temp;
		}
		else if(g < min)
		{
			tempdiff = calculatediff2(g, g);
			temp =  MAX(max - min, tempdiff);
			//fprintf(stderr, "\t< temp = %d\n", temp);
			return temp;
		}
		else
		{
			temp =  calculatediff2(max, min);
			//fprintf(stderr, "\t= temp = %d\n", temp);
			return temp;
		}
	}
	else
	{
		temp = max - min;
		//fprintf(stderr, "\t0 temp = %d\n", temp);
		return temp;
	}
}

int calculatediff3(int max, int min)
{
	int g, diff;
	if(n)
	{
		scanf("%d", &g);
		n--;
		if(g > max)
			return calculatediff3(g, min);
		else if(g < min)
		{
			diff = calculatediff3(g, g);
			return MAX(max - min, diff);
		}
		else
			return calculatediff3(max, min);
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
		if(n > 1)
		{
			scanf("%d", &g);
			n--;
			maxdiff = calculatediff3(g, g);
		}
		if(maxdiff)
			printf("%d\n", maxdiff);
		else
			printf("UNFIT\n");
	}
	return 0;
}

