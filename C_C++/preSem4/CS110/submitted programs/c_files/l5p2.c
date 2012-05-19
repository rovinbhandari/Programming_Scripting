#include <stdio.h>
#include <string.h>
int main()
{
	char p[500], q[500];
	int flag = 1, i, j;
	printf("\nEnter the main string\n");
	gets(q);
	printf("\nEnter the test string\n");
	gets(p);
	for(i = 0; q[i] != '\0'; i++)
	{
		if(q[i] == p[0])
		{
			for(j = 1; p[j] != '\0'; j++)
			{
				if(p[j] != q[i + j])
				{
					flag = 1;
					//i += strlen(p);
					break;
				}
				else
				{
					flag = 0;
				}
			}
			if(flag == 0)
			{
				break;
			}
		}
	}
	if(flag == 0)
	{
		printf("\n The test string is a substring of the main string\n");
	}
	else
	{
		printf("\nThe test string is NOT a substring of the main string\n");
	}
	return(0);
}
