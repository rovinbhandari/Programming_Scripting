#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		char a[100];
		scanf("%s",a);
		int j;
		int c1=0,c2=0,c3=0,c4=0;
		for(j=0;j<strlen(a);j++)
		{
			if(a[j]=='R')
				c1++;
			else if(a[j]=='G')
				c2++;
			else if(a[j]=='B')
				c3++;
			else
				c4++;
		}
		if (c1%2==0 && c2%2==0 && c3%2==0 && c4%2==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

