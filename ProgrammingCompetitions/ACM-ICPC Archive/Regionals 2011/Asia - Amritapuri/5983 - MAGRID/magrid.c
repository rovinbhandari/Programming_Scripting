#include <stdio.h>

#define DBG 0

#define RCMAX 500

int s[RCMAX][RCMAX];
int r, c;

typedef struct
		{
			int row;
			int col;
		}
		parent;
parent p[RCMAX][RCMAX];

inline void updatewithleftcell(i, j)
{
	s[i][j] += s[i][j - 1];
	p[i][j].row = i;
	p[i][j].col = j - 1;
}

inline void updatewithtopcell(i, j)
{
	s[i][j] += s[i - 1][j];
	p[i][j].row = i - 1;
	p[i][j].col = j;
}

int minstr()
{
	// for each steplength from 1 to (r - 1) + (c - 1) \
	update all the cells reachable with this steplength \
	using values in their left (if it exists) and top \
	(if it exists) cells.
	// updations have to choose the maximum value possible.
	// for each updatation in s, also update the parent in p.
	int i, j, steplength;
	for(steplength = 1; steplength <= (r - 1) + (c - 1); steplength++)
	{
		for(i = 0, j = steplength; j >= 0; i++, j--)
		{
			if(i >= r || j >= c)
				continue;
			
			// update leftmost cells
			if(!i)
				updatewithleftcell(i, j);
			// update topmost cells
			else if(!j)
				updatewithtopcell(i, j);
			// update all other cells
			else
			{
				if(s[i][j - 1] > s[i - 1][j])
					updatewithleftcell(i, j);
				else
					updatewithtopcell(i, j);
			}
		}
	}
	if(DBG)
	{
		for(i = 0; i < r; i++)
		{
			for(j = 0; j < c; j++)
				printf("%d ", s[i][j]);
			printf("\n");
		}
		for(i = 0; i < r; i++)
		{
			for(j = 0; j < c; j++)
				printf("(%d,%d) ", p[i][j].row, p[i][j].col);
			printf("\n");
		}
	}
	int minvalue = 1001;	// = maximum value of an element of s plus 1.
	i = p[r - 1][c - 1].row;
	j = p[r - 1][c - 1].col;
	steplength = 1;
	do
	{
		if(minvalue > s[i][j])
			minvalue = s[i][j];
		i = p[i][j].row;
		j = p[i][j].col;
		steplength++;
	}
	while(steplength <= (r - 1) + (c - 1));
	return 1 - minvalue;
}

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
		printf("%d\n", minstr());
	}
	return 0;
}

