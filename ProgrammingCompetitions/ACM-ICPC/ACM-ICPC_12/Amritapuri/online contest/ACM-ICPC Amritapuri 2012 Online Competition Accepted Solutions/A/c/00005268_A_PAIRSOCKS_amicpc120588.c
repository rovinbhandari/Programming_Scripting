#include<stdio.h>

int main()
{
int T,i;
int R , G , B, W ;
char ch;


scanf ("%d",&T);
ch = getchar();

for (i=0; i<T; i++)
{

	R = 0;
	G = 0;
	B = 0;
	W = 0;
	ch=getchar();
	while (ch != '\n')
	{
		switch (ch)
		{
		case 'R':
			{
			R = R ^ 1;
			break;
			}
		case 'G':
			{
			G = G ^ 1;
			break;
			}
		case 'B':
			{
			B = B ^ 1;
			break;
			}
		case 'W':
			{
			W = W ^ 1;
			break;
			}
		}

		ch = getchar();
	}
	if ( (R | G | B | W) ==0)
	{
		printf("YES\n");
	}
	else
	{	printf("NO\n");
	}


}


return 0;


}

