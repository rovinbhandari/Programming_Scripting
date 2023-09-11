#include <stdio.h>
#include <cmath>

void func(int L[], long long int A[], long long int B[], long long int C[], int n, int m)
{
	
	int i=0;
	long double root[m];
	for(i=0; i<m; i++)
	{
		long double sos = (A[i]*A[i] + B[i]*B[i] + C[i]*C[i]);
		root[i] = sqrt(sos);	
	}

	long double largest = root[0];
	
	for(i=1; i<m; i++)
	{
		if(root[i]> largest)
		{
			largest = root[i];
		}
	}
	
	int j=0;
	int count=0;
		
	for(j=0; j<n; j++)
	{
		if(L[j]<=largest)
			count++;
		
	}
	printf("%d\n", count);
}

int main()
{
	int test_cases=0;
	scanf("%d", &test_cases);
	int k=0;
	for(k=0; k<test_cases; k++)
	{
		int n=0, m=0;
		int i=0;
		scanf("%d %d", &n, &m);
		int L[n];
		long long int A[m];
		long long int B[m];
		long long int C[m];
		for(i=0; i<n; i++)
		{
			scanf("%d", &L[i]);
		}
		for(i=0; i<m; i++)
		{
			scanf("%lld %lld %lld", &A[i], &B[i], &C[i]);
		}
		func(L,A,B,C,n,m);
	}
return 0;
}
