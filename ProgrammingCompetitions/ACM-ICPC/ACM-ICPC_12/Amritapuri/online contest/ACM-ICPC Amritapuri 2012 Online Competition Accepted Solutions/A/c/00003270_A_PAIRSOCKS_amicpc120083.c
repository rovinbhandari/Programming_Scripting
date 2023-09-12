#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int t=0;
	scanf("%d",&t);
	char st[55];
	int R=0,G=0,W=0,B=0;
	int i=0,j=0;
	for(i=0;i<t;i++)
	{
		scanf("%s",st);
		R=0;
		G=0;
		B=0;
		W=0;
		for(j=0;j<strlen(st);j++)
		{
			if(st[j]=='R')
				R++;
			else if(st[j]=='G')
				G++;
			else if(st[j]=='B')
				B++;
			else if(st[j]=='W')
				W++;
		}
		if(R%2==0 && G%2==0 && B%2==0 && W%2==0)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
