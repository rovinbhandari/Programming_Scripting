#include <stdio.h>
#include <math.h>

int approxdigitsinfactorial(int x)
{
	double N = 0.0;
	int i = 0;
	while(++i <= x)
		N += log10(i);		// because log10(i) computes the contribution to the number of digits by i in the multiplication result. e.g., log10(100) = 2
	return (((int) N) + 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", approxdigitsinfactorial(n));
	return 0;
}
