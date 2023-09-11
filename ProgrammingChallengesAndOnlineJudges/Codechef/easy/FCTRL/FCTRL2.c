/*
	Rovin Bhandari
	29/8/2011
	
	FCTRL
*/

#include<stdio.h>

int z(int n)
{
	if(n < 5)
		return 0;
	else
	{
		int sum = 0, m;
		while(m = n /= 5)
			sum += m;
		return sum;
	}
}

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		printf("%d\n", z(n));
	}
	return 0;
}
