#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{
	long long int t, n, m, i, j, temp, count, max;
	scanf("%lld", &t);
	while(t--)
	{
		count = 0;
		max = 0;
		scanf("%lld %lld", &n, &m);
		long long int *l = (long long int *)malloc(n*sizeof(long long int));
		long long int *a = (long long int *)malloc(m*sizeof(long long int));
		long long int *b = (long long int *)malloc(m*sizeof(long long int));
		long long int *c = (long long int *)malloc(m*sizeof(long long int));
		for(i=0; i<n; i++)
			scanf("%lld", &l[i]);
		for(i=0; i<m; i++)
		{
			scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
			temp = sqrt(a[i]*a[i] + b[i]*b[i] + c[i]*c[i]);
			if(temp >= max)
				max = temp;
		}
		for(i=0; i<n; i++)
		{
			if(l[i] <= max)
				count++;
		}
		printf("%lld\n", count);
	}
	return 0;
}