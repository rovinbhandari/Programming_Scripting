#include <stdio.h>

inline int getint(void);
inline void putint(int);

int nothing(int x)
{
	return x;
}

int main(void)
{
	int t, n;
	t = getint();
	while(t--)
	{
		n = getint();
		putint(nothing(n));
		putchar('\n');
	}
	return 0;
}

inline int getint(void)
{
	int N = 0;
	char c;
	while((c = getchar()) != '\n' && c != EOF && c != ' ')
		N = N * 10 + (c - '0');
	return N;
}

inline void putint(int N)
{
	if(N < 0)
	{
		putchar('-');
		N *= -1;	// check for potential overflows
	}
	if(N >= 10)
		putint(N / 10);
	putchar((N % 10) + '0');
}

