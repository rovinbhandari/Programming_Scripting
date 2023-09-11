/*
	Rovin Bhandari
	6/10/2011
	
	DCE05
*/

#include <stdio.h>
#include <math.h>

inline int getint();
inline void putint(int);

int main()
{
	int t;
	t = getint();
	while(t--)
	{	putint(1 << ((int) (floor(log2(getint())))));
		putchar('\n');
	}
	return 0;
}

inline int getint()
{
	int N = 0;
	char c;
	while((c = getchar()) != '\n' && c != EOF)
		N = N * 10 + (c - '0');
	return N;
}

inline void putint(int N)
{
	if(N >= 10)
		putint(N / 10);
	putchar((N % 10) + '0');
}

