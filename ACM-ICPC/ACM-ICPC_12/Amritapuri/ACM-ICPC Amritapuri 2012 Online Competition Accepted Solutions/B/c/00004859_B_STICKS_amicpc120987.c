#include<stdio.h>
int main()
{
	int test_cases;
	int sticks, boxes;
	long long int max_diag;
	scanf("%d", &test_cases);
	long long int sol[test_cases];
	int i, j;
	for(i=0;i<test_cases;i++)
	{
		sol[i] = 0;
		scanf("%d %d", &sticks, &boxes);
		long long int length[sticks], l[boxes], b[boxes], h[boxes], d[boxes];
		for(j=0;j<sticks;j++)
		{
			scanf("%lld", &length[j]);
		}	
		max_diag = -1;
		for(j=0;j<boxes;j++)
		{
			scanf("%lld %lld %lld", &l[j], &b[j], &h[j]);
			d[j] = l[j]*l[j] + b[j]*b[j] + h[j]*h[j];
			if(d[j]>max_diag)
				max_diag = d[j];
		}
		for(j=0;j<sticks;j++)
		{
			if(length[j]*length[j] <= max_diag)
				sol[i]++;
		}
	}
	for(i=0;i<test_cases;i++)
	{
		printf("%lld\n", sol[i]);
	}	
	return 0;
}
