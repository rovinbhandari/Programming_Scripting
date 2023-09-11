#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int len;
		char a[50];
		scanf("%s",a);
		len=strlen(a);
		if(len%2==1)
			printf("NO\n");
		else
		{
			int i;
			char count[4]={0};
			for(i=0;i<len;i++)
			{
				if(a[i]=='R')
					count[0]++;
				else if(a[i]=='G')
					count[1]++;
				else if(a[i]=='B')
					count[2]++;
				else if(a[i]=='W')
					count[3]++;
			}
			int flag=0;
			for(i=0;i<4;i++)
			{
				if(count[i]%2==1)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
