/*
	Rovin Bhandari
	31/8/2011
	
	DCE05
*/

#include<stdio.h>

int titanic(int n, int p)
{
	if(n == 0)
		return p;
	else
		return (titanic(n / 2, ++p));
}

int main()
{
	int T, N, pow, ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		pow = titanic(N, 0) - 1;
		ans = 1;
		while(pow--)
			ans *= 2;
		printf("%d\n", ans);
	}
	return 0;
}
