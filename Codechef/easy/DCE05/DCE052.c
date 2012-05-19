/*
	Rovin Bhandari
	30/8/2011
	
	DCE05
*/

#include<stdio.h>
#include<math.h>

int titanic(int n, int p)
{
	if(n == 0)
		return p;
	else
		return (titanic(n / 2, ++p));
}

int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		printf("%d\n", (int) pow(2, titanic(N, 0) - 1));
	}
	return 0;
}
