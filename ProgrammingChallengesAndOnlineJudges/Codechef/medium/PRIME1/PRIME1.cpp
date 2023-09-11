/*
	Rovin Bhandari
	31/8/2011

	PRIME1
*/

#include<cstdio>
#include<cmath>
using namespace std;

int i, sq;

bool isPrime(int x)
{
	if(x == 1)
		return false;
	else if(x == 2)
		return true;
	else
	{
		i = 1;
		while(++i < x)
			if(!(x % i))
				return false;
		return true;
	}
}

bool isPrime2(int x)
{
	sq = (int) floor(sqrt(x));	// check if the root is rational
	i = 21;
	while((i += 2) < sq + 1)
	{
		//if(!(i % 3 && i % 5 && i % 7 && i % 11 && i % 13 && i % 17 && i % 19))
		//	continue;
		if(!(x % i))
			return false;
	}
	return true;
}

void primes(int a, int b)
{
	if(a > 20)
	{
		if(!(a % 2))
			a++;	
		do
		{
			if(!(a % 3 && a % 5 && a % 7 && a % 11 && a % 13 && a % 17 && a % 19))
				continue;
			if(isPrime2(a))
				printf("%d\n", a);
		}

		while((a += 2) < b);
	}
	else if(b <= 20)
	{
		do
		{
			if(isPrime(a))
				printf("%d\n", a);
		}
		while(a++ < b);
	}
	else
	{
		primes(a, 20);
		primes(21, b);
	}
}

int main()
{
	int T, a, b;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &a, &b);
		primes(a, b);
		printf("\n");
	}
	return 0;
}
