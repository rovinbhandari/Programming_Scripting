#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

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
		i = n;
		while(i--)
		{
			scanf("%d", &intervalsX[i].x);
			scanf("%d", &intervalsX[i].y);
			intervalsY[i] = intervalsX[i];
		}
		sort(&intervalsX[0], &intervalsX[n], interval::comparatorX);
		sort(&intervalsY[0], &intervalsY[n], interval::comparatorY);
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

