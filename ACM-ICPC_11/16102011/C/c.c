#include <stdio.h>

int main()
{
	int instsum, mininstsum, t, n, in;
	scanf("%d", &t);
	while(t--)
	{
		mininstsum = 1;
		instsum = 0;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d", &in);
			instsum += in;
			if(instsum < mininstsum)
				mininstsum = instsum;
		}
		if(mininstsum >= 1)
			printf("1\n");
		else
			printf("%d\n", (mininstsum * (-1) + 1));
	}
	return 0;
}

