/*
	Rovin Bhandari
	29/8/2011
	
	FCTRL
*/

#include<stdio.h>

int multiplicity5(int m)
{
	int m5 = 1;
	while((m /= 5) % 5 == 0)
		m5++;
	return m5;
}

int z(int n)
{
	if(n < 5)
		return 0;
	else
	{
		int sum = 0, m = 5;
		do
			sum += multiplicity5(m);
		while((m += 5) <= n);
		return sum;
	}
}

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t-- > 0)
	{
		scanf("%d", &n);
		printf("%d\n", z(n));
	}
	return 0;
}
