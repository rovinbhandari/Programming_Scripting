#include <stdio.h>
#include <math.h>

int xroot, i, j;

int isprime(int x)
{
	xroot = ((int) sqrt(x)) + 1;
	i = 1;
	while((i += 2) <= xroot)
		if(!(x % i))
			return 0;
	return 1;
}

int main()
{
	int t, x;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &x);
		if(x == 1)
			printf("2\n");
		else if(x == 2)
			printf("2\n");
		else
		{
			if(!(x % 2))
				x++;
			j = x;
			while(1)
			{
				if(isprime(j))
				{
					printf("%d\n", j);
					break;
				}
				j += 2;
			}
		}
	}
	return 0;
}
