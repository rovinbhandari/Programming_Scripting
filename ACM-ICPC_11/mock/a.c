#include <stdio.h>

int max, min;

int main()
{
	int t, n, in;
	scanf("%d", &t);
	while(t--)
	{
		max = -1;
		min = 1000001;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d", &in);
			if(max < in)
				max = in;
			if(min > in)
				min = in;
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}
