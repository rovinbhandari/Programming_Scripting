#include <stdio.h>
main()
{
	int a = 1, b, c, d, t, x;
	long long n;
	scanf("%d", &t);
	while(t--)
	{	
		n = 0;
		scanf("%d", &x);
		for( ; a <= x; a++)
			for(b = 2, c = 3, d = 4; b <= x && (a + b + c + d) < (x - 4); b++)
			{
				for(c = 3, d = 4; c <= x && (a + b + c + d) < (x - 4); c++)
				{
					for(d = 4; d <= x && (a + b + c + d) < (x - 4); d++)
						n++;
					d = 4;
				}
				c = 3;
			}	
		printf("%lld\n", n);
	}
}

