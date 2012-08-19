#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define DBGSTR "DBG:\t"
#define DBGINI stderr, DBGSTR

#define MAXN 10000

struct interval
{
	int x;
	int y;
	
	static bool comparatorX(const interval& a, const interval& b)
	{
		return a.x < b.x;
	}
	
	static bool comparatorY(const interval& a, const interval& b)
	{
		return a.y < b.y;
	}
};

void fprintfarray(interval* arr, int l)
{
	int i = -1;
	while(++i < l)
		fprintf(stderr, "(%d:%d) ", arr[i].x, arr[i].y);
	fprintf(stderr, "\n");
}

interval intervalsX[MAXN + 1];
interval intervalsY[MAXN + 1];

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
		sort(&intervalsX[0], &intervalsX[n], interval::comparatorX);
		sort(&intervalsY[0], &intervalsY[n], interval::comparatorY);
		fprintf(DBGINI " sort(): intervalsX = ");
		fprintfarray(intervalsX, n);
		fprintf(DBGINI " sort(): intervalsY = ");
		fprintfarray(intervalsY, n);
		intersections = 0;
		for(i = 0; i < n; i++)
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
		printf("%d\n", intersections);
	}
	return 0;
}

