#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INMAX 1000000

typedef unsigned int ui;

ui mem[INMAX + 1] = {0};

ui cyclelength(ui n)
{
	ui temp;
	if(n <= INMAX && mem[n])
		return mem[n];
	else
	{
		temp = 1 + cyclelength(n & 1 ? n + n + n + 1 : n >> 1);
		if(n <= INMAX)
			mem[n] = temp;
		return temp;
	}
}

#define MIN(a, b) ((a < b) ? a : b)
#define MAX(a, b) ((a > b) ? a : b)

int main(void)
{
	ui i, j, l, h, k, temp, maxcyclelength;
	mem[1] = 1;
	while(scanf("%u %u", &i, &j) != EOF)
	{
		maxcyclelength = 0;
		/* Since i < j is not given... */
		l = MIN(i, j);
		h = MAX(i, j);
		for(k = l; k <= h; k++)
		{
			temp = cyclelength(k);
			#ifdef DBG
			printf("%u %u\n", k, temp);
			#endif
			#ifdef DBGc
			printf("%u, ", temp);
			#endif
			if(maxcyclelength < temp)
				maxcyclelength = temp;
		}
		#ifdef DBGc
		printf("\n");
		#endif
		printf("%u %u %u\n", i, j, maxcyclelength);
	}

	return 0;
}

