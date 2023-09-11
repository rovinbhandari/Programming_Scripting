/*
	Rovin Bhandari
	11/10/2011
	
	FCTRL2
*/

#include <stdio.h>

int * memarr[101][170] = {0};		// choice of 170 is based on the output of "C_C++/estimating_number_of_digits_in_n!.c.out" with input 100.

int ncopy, i, index, ndigits;

void init()
{
	memarr[0] = malloc(sizeof(int));
	memarr[1] = malloc(sizeof(int));
	memarr[0][0] = memarr[1][0] = 1;
	for(i = 2; i < 101; i++)
		memarr[i] = NULL;
}

void copy(int n)
{

}

int multiply(int a)
{

}

int * factorial(int n)
{
	if(!memarr[n])
		return memarr[n];
	else
	{
		bindex = 0;
		i = n;
		while(!memarr[--i]);
		copy2bignum(i);
		while(++i <= n)
			multiply(i);
		copy2memarr(n);
		return bignum;
	}		
}

void print(int * bignum)
{

}

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		print(factorial(n));
	}
	return 0;
}
