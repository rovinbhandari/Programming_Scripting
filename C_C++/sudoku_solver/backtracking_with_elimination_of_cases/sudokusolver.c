#include <sudokusolver.h>

#define SQ(x)	(x) * (x)

static Bool checkelem_(GridElem x)
{
	if(x >= 1 && x <= SIZEGRID)
		return TRUE;
	return FALSE;
}
		
void readgrid(GridElem g[SIZEGRID][SIZEGRID], FILE* f)
{
	GridElem x;
	int i = 0;
	while(!feof(f))
	{
		fscanf(f, "%hu", &x);
		if(checkelem_(x) || x == 0)
		{
			g[i / SIZEGRID][i % SIZEGRID] = x;

			i++;
			if(i == SQ(SIZEGRID))
				break;
		}
		else
			ERX("Bad Input", 5);
	}
	if(i != SQ(SIZEGRID))
		ERX("Insufficient Input", 6);
}

Bool evaluategrid(GridElem g[SIZEGRID][SIZEGRID])
{
	return FALSE;
}

void printgrid(GridElem g[SIZEGRID][SIZEGRID])
{
	int i, j;
	for(i = 0; i < SIZEGRID; i++)
	{
		for(j = 0; j < SIZEGRID; j++)
			printf("%hu ", g[i][j]);
		printf("\n");
	}
}

