#include <stdio.h>

#define RCMAX 500

int s[RCMAX][RCMAX];
int r, c;

void dbgprintarray();
int minstr();

int main(void)
{
	int i, j, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &r);
		scanf("%d", &c);
		for(i = 0; i < r; i++)
			for(j = 0; j < c; j++)
				scanf("%d", &s[i][j]);
		dbgprintarray();
		printf("%d\n", minstr());
	}
	return 0;
}

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define LEASTNATURAL(x) (((x) <= 0) ? 1 : (x))

int minstr()
{
	int i, j;
	s[r - 1][c - 1] = 1;
	for(j = c - 2; j >= 0; j--)
		s[r - 1][j] = LEASTNATURAL(s[r - 1][j + 1] - s[r - 1][j]);
	dbgprintarray();
	for(i = r - 2; i >= 0; i--)
		s[i][c - 1] = LEASTNATURAL(s[i + 1][c - 1] - s[i][c - 1]);
	dbgprintarray();
	for(i = r - 2; i >= 0; i--)
		for(j = c - 2; j >= 0; j--)
			s[i][j] = MIN(LEASTNATURAL(s[i + 1][j] - s[i][j]), 
						  LEASTNATURAL(s[i][j + 1] - s[i][j]));
	dbgprintarray();
	return s[0][0];
}

void dbgprintarray()
{
	#ifdef DBG
	int i, j;
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
			printf("%d ", s[i][j]);
		printf("\n");
	}
	printf("\n");
	#endif
	return;
}

