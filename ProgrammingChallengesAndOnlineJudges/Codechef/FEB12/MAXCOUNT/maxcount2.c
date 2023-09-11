#include <stdio.h>
#include <string.h>

inline int getint(void);
inline void putint(int);

#define MAX 10000
typedef unsigned short int usi;

int main(void)
{
	int t, n;
	usi a[MAX], maxcount, minindex, i, max;
	
	t = getint();
	while(t--)
	{	
		maxcount = max = minindex = 0;
		memset(a, 0, sizeof(usi) * MAX);
		
		n = getint();
		while(n--)
		{
			if(++a[i = (usi) (getint() - 1)] > max)
			{
				if((max = a[i]) == maxcount && i < minindex)
				{
					minindex = i;
				}
				else if(max > maxcount)
				{
					maxcount = max;
					minindex = i;
				}
				
			}
		}
		
		
		putint((int) (minindex + 1));
		putchar(' ');
		putint((int) maxcount);
		
		putchar('\n');
		
		for(i = 0; i < MAX; i++)
			if(a[i])
				printf("###\t\t%d : %d\n", i + 1, a[i]);
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

