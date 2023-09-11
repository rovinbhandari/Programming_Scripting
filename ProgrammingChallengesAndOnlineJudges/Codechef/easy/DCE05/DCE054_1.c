/*
	Rovin Bhandari
	6/10/2011
	
	DCE05
*/

#include <stdio.h>
#include <math.h>

int getint();
void putint(int);

int main()
{
	int t;
	t = getint();
	while(t--)
	{	putint(1 << ((int) (log2(getint()))));
		putchar('\n');
	}
	return 0;
}

int getint()
{
	int N = 0;
	char c;
	while((c = getchar()) != '\n' && c != EOF)
		N = N * 10 + (c - '0');
	return N;
}

void putint(int N)
{
	if(N >= 10)
		putint(N / 10);
	putchar((N % 10) + '0');
}

