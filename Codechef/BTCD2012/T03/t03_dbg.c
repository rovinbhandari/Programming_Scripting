#include <stdio.h>
#include <stdlib.h>

#define DBGSTR "DBG:\t"
#define DBGINI stderr, DBGSTR

#define MAXN 10000

typedef struct _interval
		{
			int x;
			int y;
		}
		interval;

void fprintfarray(interval* arr, int l)
{
	int i = -1;
	while(++i < l)
		fprintf(stderr, "(%d:%d) ", arr[i].x, arr[i].y);
	fprintf(stderr, "\n");
}

interval intervalsX[MAXN];
interval intervalsY[MAXN];

int comparatorX(interval* a, interval* b)
{
	return a->x - b->x;
}

int comparatorY(interval* a, interval* b)
{
	return a->y - b->y;
}

int main(void)
{
	int t, n;
	int i, j, intersections;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		fprintf(DBGINI "\nn = %d\n", n);
		i = n;
		while(i--)
		{
			scanf("%d", &intervalsX[i].x);
			scanf("%d", &intervalsX[i].y);
			intervalsY[i] = intervalsX[i];
		}
		fprintf(DBGINI "scanf(): intervalsX = ");
		fprintfarray(intervalsX, n);
		fprintf(DBGINI "scanf(): intervalsY = ");
		fprintfarray(intervalsY, n);
		qsort(intervalsX, n, sizeof(interval), comparatorX);	// why is there a warning here?
		qsort(intervalsY, n, sizeof(interval), comparatorY);	// why is there a warning here?
		fprintf(DBGINI "qsort(): intervalsX = ");
		fprintfarray(intervalsX, n);
		fprintf(DBGINI "qsort(): intervalsY = ");
		fprintfarray(intervalsY, n);
		intersections = 0;
		fprintf(DBGINI "intersections = %d\n", intersections);
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				if(intervalsY[j].y >= intervalsX[i].y)
					break;
				else if(intervalsY[j].x > intervalsX[i].x)
				{
					fprintf(DBGINI "intersection between = (%d:%d) and (%d:%d)\n", intervalsX[i].x, intervalsX[i].y, intervalsY[j].x, intervalsY[j].y);
					intersections++;
					fprintf(DBGINI "intersections = %d\n", intersections);
				}
			}
		}
		printf("%d\n", intersections);
	}
	return 0;
}

