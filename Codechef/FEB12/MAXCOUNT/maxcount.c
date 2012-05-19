#include <stdio.h>
#include <string.h>

inline int getint(void);
inline void putint(int);

#define MAX 10000
typedef unsigned short int usi;

usi a[MAX];

void result(void)
{
	usi maxcount, minindex, i, max;
	maxcount = minindex = i = max = 0;

	do
	{
		if(!a[i])			// for better speed of execution (tested @ CodeChef)
			;
		else if(a[i] > max)
		{
			max = a[i];
			if(max > maxcount)
			{
				maxcount = max;
				minindex = i;
			}
		}
	}
	while(++i < MAX);

	putint((int) (minindex + 1));
	putchar(' ');
	putint((int) maxcount);
}

int main(void)
{
	int t, n;
	
	t = getint();
	while(t--)
	{	
		memset(a, 0, sizeof(usi) * MAX);
		
		n = getint();
		while(n--)
			a[getint() - 1]++;
	
		result();
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

