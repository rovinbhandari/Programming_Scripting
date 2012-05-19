#include <stdio.h>
#include <math.h>

#define TOLERANCE 0.00001

long double hcfld(long double a, long double b)
{
	long double t;
	while(fabsl(b - 0.0d) > TOLERANCE)
	{
		t = b;
		b = fmodl(a, b);
		a = t;
	}

	return a;
}

int main(void)
{
	int t;
	long double a, b;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%Lf %Lf", &a, &b);
		printf("%Lf\n", hcfld(a, b));
	}

	return 0;
}

