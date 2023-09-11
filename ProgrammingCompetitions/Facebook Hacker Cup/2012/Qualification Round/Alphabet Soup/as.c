#include <stdio.h>
#include <string.h>

#define H 0
#define A 1
#define C 2
#define K 3
#define E 4
#define R 5
#define U 6
#define P 7

#define LENa		8

#define MAXLENin	1000

int a[LENa];

int findmin(void)
{
	int min = MAXLENin + 1, i = 0;
	
	while(i < LENa)
	{
		if(a[i] < min)
			min = a[i];
		i++;
	}

	return min;
}

int main(void)
{
	int t, i, n;
	scanf("%d", &t);
	getchar();	// for removing the '\n' which comes along the ENTER of scanf

	char c;
	
	for(i = 1; i <= t; i++)
	{
		memset(a, 0, LENa * sizeof(int));

		while((c = getchar()) != '\n' && c != EOF)
		{
			switch(c)
			{
				case 'H':	a[H]++; break;
				case 'A':	a[A]++; break;
				case 'C':	a[C]++; break;
				case 'K':	a[K]++; break;
				case 'E':	a[E]++; break;
				case 'R':	a[R]++; break;
				case 'U':	a[U]++; break;
				case 'P':	a[P]++; break;
			}
		}

		n = findmin();
		if(a[C] / 2 < n)
			n = a[C] / 2;

		printf("Case #%d: %d\n", i, n);
	}

	return 0;
}

