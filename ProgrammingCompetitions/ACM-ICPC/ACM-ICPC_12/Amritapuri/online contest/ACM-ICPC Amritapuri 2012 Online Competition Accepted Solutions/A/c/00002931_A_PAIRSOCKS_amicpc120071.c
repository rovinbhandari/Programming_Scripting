#include<stdio.h>
#include<string.h>
int main()
{
	int l,m;
	scanf("%d",&m);
	for(l=0;l<m;l++)
	{
		char a[75];
		scanf("%s",a);
		int b,i,c[4];
		b=strlen(a);
		c[0]=0;
		c[1]=0;
		c[2]=0;
		c[3]=0;
		for(i=0;i<b;i++)
		{
			if(a[i]=='R')
			{
				c[0]++;
			}
			else if(a[i]=='W')
			{
				c[1]++;
			}
			else if(a[i]=='G')
			{
				c[2]++;
			}
			else
			{
				c[3]++;
			}
		}
		if(c[0]%2==0 && c[1]%2==0 && c[2]%2==0 && c[3]%2==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
