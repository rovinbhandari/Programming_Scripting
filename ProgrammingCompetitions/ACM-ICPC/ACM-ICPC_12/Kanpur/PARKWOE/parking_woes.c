#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define HOLE 2147483647

/*
int calculate_moves(int *lot, int i, int j)
{
	int move_east, move_south; 
	move_east = calculate_moves(lot, i, j+1);
	move_south = calculate_moves(lot, i+1, j);
	table[i * n + j] = (move_south > move_east) ? move_south: move

}	
*/

int min (int a, int b)
{
	return a < b ? a : b;
}


int main (void)
{
  int t; //, *lot;
  int i, j, m, n, cost;

  scanf ("%d", &t);

  while (t--)
  {
	scanf("%d %d", &m, &n);
//	lot = malloc(sizeof(int)*m*n);

	int lot[m][n], table[m][n];
	for (i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &lot[i][j]);
		}
	}
	
	table[m - 1][n - 1] = 0;
	for (i = n - 2; i >= 0; i--)
	{
		table[m - 1][i] = (lot[m - 1][i + 1] == HOLE) ? 0 : (1 + table[m - 1][i + 1]);
	}
	
	for (i = m - 2; i >= 0; i--)
	{
		table[i][n - 1] = (lot[i + 1][n - 1] == HOLE) ? 0 : (1 + table[i + 1][n - 1]);
	}

	for (i = m - 2; i >= 0; i--)
	{
		for (j = n - 2; j >= 0; j--)
		{
			if (lot[i + 1][j] == HOLE && lot[i][j + 1] == HOLE)
			{
				table[i][j] = 0;
			}
			else if (lot[i][j+1] == HOLE && lot[i + 1][j] != HOLE)
			{
				table[i][j] = 1 + table[i + 1][j];
			}
			else if (lot[i + 1][j] == HOLE && lot[i][j + 1] != HOLE)
			{
				table[i][j] = 1 + table[i][j + 1];
			}
			else
			{
				cost = INT_MAX;
				if (lot[i + 1][j] < lot[i][j + 1])
				{
					cost = min (cost, 1 + table[i + 1][j]);
				}
				
				if (lot[i][j + 1] < lot[i + 1][j])
				{
					cost = min (cost, 1 + table[i][j + 1]);
				}
				table[i][j] = cost;
			}
		}
	}
	/*
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf ("%d\t", table[i][j]);
		}
		printf ("\n");
	}
*/
//	moves = calculate_moves(lot, 0, 0);
	printf("%d\n", table[0][0]);	
//	free(lot);
//	free(table);
  }
  return 0;
}
