#include <FloydWarshall.h>
#include <stdio.h>

int main(void)
{
	ui n, m, q, u, v;
	int w;

	scanf("%u", &n);
	scanf("%u", &m);
	FWinitAM(n);
	while(m--)
	{
		scanf("%u", &u);
		scanf("%u", &v);
		scanf("%d", &w);
		FWpopulateAM(u, v, w);
	}
	FWprintAM(stderr);
	
	FWcomputeAPSPL();
	FWprintAM(stderr);

	ui i, j;
	printf("\n");
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(FWqueryshortestpath(i, j, &w))
				fprintf(stderr, "%u --> %u : %d\n", i, j, w);
			else
				fprintf(stderr, "%u --> %u : INFINITY\n", i, j);
	printf("\n");

	printf("\n");
	scanf("%u", &q);
	while(q--)
	{
		scanf("%u", &u);
		scanf("%u", &v);
		if(FWqueryshortestpath(u, v, &w))
			printf("%u --> %u : %d\n", u, v, w);
		else
			printf("%u --> %u : INFINITY\n", u, v);
	}
	printf("\n");

	return 0;
}

