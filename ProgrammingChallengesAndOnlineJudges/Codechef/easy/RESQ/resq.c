#include <stdio.h>
#include <math.h>

int main(void)
{
	int t, n, factor;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		factor = (int) (nearbyintf(floorf(sqrtf((float) n))) + 0.1f);
		while(n % factor)
			factor--;
		printf("%d\n", n / factor - factor);
	}
	return 0;
}

