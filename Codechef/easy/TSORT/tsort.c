#include <stdio.h>

inline int getint(void);
inline void putint(int);

int a[1000001];

int main(void)
{
	int t, n, max = 0, i = 0, j;
	t = getint();
	while(t--)
	{
		++a[n = getint()];
		if(n > max)
			max = n;
	}
	while(i <= max)
	{
		for(j = a[i]; j > 0; j--)
			printf("%d\n", i);
		i++;
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

