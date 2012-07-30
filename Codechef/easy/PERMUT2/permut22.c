#include <stdio.h>

int a[100001];

int main(void)
{
	int n, i;
	while(1)
	{
		ReadNewInput: scanf("%d", &n);
		if(n)
		{
			for(i = 1; i <= n; i++)
				scanf("%d", a + i);
			for(i = 1; i <= n; i++)
			{
				if(*(a + i) == -1)
					continue;
				if(i == *(a + *(a + i)))
					*(a + *(a + i)) = -1;
				else
				{
					printf("not ambiguous\n");
					goto ReadNewInput;
				}
			}
			printf("ambiguous\n");
		}
		else
			return 0;
	}
}

