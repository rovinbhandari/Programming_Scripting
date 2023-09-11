#include<stdio.h>

int main()
{
	int t,i,a[4]={0},f;
	char s[1001];

	scanf("%d",&t);

	while(t--)
	{
		scanf("%s",s);
		a[0]=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
		f=0;
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i] == 'R')	a[0]++;
			else if(s[i] == 'G') a[1]++;
			else if(s[i] == 'B') a[2]++;
			else		     a[3]++;
		}
		for(i=0;i<4;i++)
		{
			if(a[i]%2 != 0)	f=1;
		}
		if(f == 1)	printf("NO\n");
		else		printf("YES\n");
	}

	return 0;
}
