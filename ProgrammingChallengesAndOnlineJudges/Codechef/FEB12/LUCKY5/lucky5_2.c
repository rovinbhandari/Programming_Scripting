#include <stdio.h>

char num[100001];

int main(void)
{
	int t, count, i;
	char c;
	scanf("%d", &t);	
	while(t--)
	{	
		count = i = 0;
		scanf("%s", num);
		while(c = num[i++])
			if(c != '4' && c != '7')
				count++;
		printf("%d\n", count);		
	}
	return 0;
}

