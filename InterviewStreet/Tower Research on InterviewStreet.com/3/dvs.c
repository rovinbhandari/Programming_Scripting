#include <stdio.h>

typedef long long int lli;

lli sumb(lli n)
{
	lli s = 0;
	while(n - 4 > 0)
	{
		s += (n - 4) * (n - 4);
		n = n - 4;
	}
	return s;
}

int main(void)
{
	int t;
	lli n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld", &n);
		lli b = sumb(n);
		lli a = (n * (n + 1) * (2 * n + 1)) / 6 - b;
		printf("%lld\n", a);
	}
	return 0;
}

