#include<stdio.h>
#include<string.h>
int main()
{
	int t,len,flag=0,i;
	char str[51],color[4];
	scanf("%d",&t);

	while(t--)
	{
		flag=0;

		for(i=0;i<4;i++)
			color[i]=0;

		scanf("%s",str);
		len=strlen(str);
		for(i=0;i<len;i++)
		{
			switch (str[i])
			{
			case 'R':
				color[0]++;
				break;
			case 'G':
				color[1]++;
				break;
			case 'B':
				color[2]++;
				break;
			case 'W':
				color[3]++;
				break;
			default:
				break;
			}

		}
		for(i=0;i<4;i++)
			if(color[i]%2)
				flag=1;
		if(!flag)
			printf("YES\n");
		else
			printf("NO\n");
		
	}
	return 0;
}