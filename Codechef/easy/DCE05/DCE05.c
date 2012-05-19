/*
	Rovin Bhandari
	30/8/2011
	
	DCE05
*/


// gives wrong answer due to the fact that 3 returns 2 but it is not valid in some cases.


#include<stdio.h>

int h;
//int k;

int titanic(int n)
{
	if(n == 1)
		return 1;
	else if(n == 2 || n == 3)
		return 2;
	else
	{
		h = n / 2;
		//k = (titanic(h) + titanic(n - h));
		//fprintf(stderr, "%d\n", k);
		//return k;
		return (titanic(h) + titanic(n - h));
	}
}

int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		printf("%d\n", titanic(N));
	}
	return 0;
}
