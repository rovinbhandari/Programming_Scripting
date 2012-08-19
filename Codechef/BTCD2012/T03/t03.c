#include <stdio.h>
#include <stdlib.h>

#define MAXN 10000

typedef struct _interval
		{
			int x;
			int y;
		}
		interval;

interval intervalsX[MAXN];
interval intervalsY[MAXN];

int comparatorX(const void* a, const void* b)
{
	return ((interval*) a)->x - ((interval*) b)->x;
}

int comparatorY(const void* a, const void* b)
{
	return ((interval*) a)->y - ((interval*) b)->y;
}

int main(void)
{
	int t, n;
	int i, j, intersections;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		i = n;
		while(i--)
		{
			scanf("%d", &intervalsX[i].x);
			scanf("%d", &intervalsX[i].y);
			intervalsY[i] = intervalsX[i];
		}
		qsort(intervalsX, n, sizeof(interval), comparatorX);
		qsort(intervalsY, n, sizeof(interval), comparatorY);
		intersections = 0;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
			{
				if(intervalsY[j].y >= intervalsX[i].y)
					break;
				else if(intervalsY[j].x > intervalsX[i].x)
					intersections++;
			}
		printf("%d\n", intersections);
	}
	return 0;
}

