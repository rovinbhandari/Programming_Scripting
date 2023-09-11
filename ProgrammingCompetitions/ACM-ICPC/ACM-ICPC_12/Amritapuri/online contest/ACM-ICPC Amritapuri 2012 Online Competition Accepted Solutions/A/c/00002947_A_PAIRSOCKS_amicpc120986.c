#include<stdio.h>
#include<string.h>

int main()
{
	int t,i,len;
	int paircount[4];
	char c[50];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",c);
		len=strlen(c);
		for(i=0;i<4;i++)
			paircount[i]=0;
		for(i=0;i<len;i++)
		{
			switch (c[i])
			{
				case 'R':
						paircount[0]++;
						break;
				case 'G':
						paircount[1]++;
						break;
				case 'B':
						paircount[2]++;
						break;
				case 'W':
						paircount[3]++;
						break;
			}
		}
		if(((paircount[0] % 2)==0) && ((paircount[1] % 2)==0) && ((paircount[2] % 2)==0) && ((paircount[3] % 2)==0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
