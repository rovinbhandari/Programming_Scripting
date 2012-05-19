/*
	Rovin Bhandari
	11/10/2011
	
	DCE05
*/

#include <stdio.h>
#include <math.h>

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		printf("%d\n", 1 << ((int) (log2(n))));
	}
	return 0;
}

