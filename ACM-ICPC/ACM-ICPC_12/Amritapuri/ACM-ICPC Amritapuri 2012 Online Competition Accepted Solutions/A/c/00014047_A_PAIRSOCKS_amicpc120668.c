#include<stdio.h>
#include<string.h>
void main()
{
	int tc, i, cntr=0, cntb=0, cntg=0, 	cntw=0, j;
	char str[1001][51];
	scanf("%d", &tc);
	if(tc>=1 && tc<=1000)
	{
		for(i=0; i<=tc;i++)
		{
				gets(str[i]);
		}
		for(i=1; i<=tc; i++)
		{
			for(j=0;str[i][j]!='\0';j++)
			{
				if(strlen(str[i])<=50)
				{
					if(str[i][j] == 'R' || str[i][j] == 'W' || str[i][j] == 'G' || str[i][j] == 'B')
					{
						if(str[i][j] == 'R')
						{
							cntr++;
						}
						if(str[i][j] == 'B')
						{
							cntb++;
						}
						if(str[i][j] == 'G')
						{
							cntg++;
						}
						if(str[i][j] == 'W')
						{
							cntw++;
						}
					}
					else
						goto next;
				}
				else
				{
					goto next;
				}
			}
			if(cntr%2==0 && cntb%2==0 && cntw%2==0 && cntg%2==0)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
			cntr=0;
			cntb=0;
			cntg=0;
			cntw=0;
		}
	}
	else
		{
			goto next;
		}
		next:
			exit(0);
}