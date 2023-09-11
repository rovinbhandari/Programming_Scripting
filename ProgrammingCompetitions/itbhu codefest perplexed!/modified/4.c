#include <stdio.h>
#include <math.h>
main()
{
	int c, x, i, j, d;
	scanf("%d", &c);
	while(c--)
	{
		d = 1;
		scanf("%d", &x);
		for(i = 2; i <= x / 2; i++)
			for(j = 2; j <= x; j++)
				if(pow(i, j) == x && d < j)
					d = j;
		printf("%d\n", d);
	}
}
