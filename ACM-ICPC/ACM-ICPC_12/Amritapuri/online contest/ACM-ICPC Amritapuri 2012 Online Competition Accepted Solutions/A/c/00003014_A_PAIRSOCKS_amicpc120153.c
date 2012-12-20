#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	char s[100000];
	scanf("%s",s);
	int len = strlen(s);
	int i=0;
	int c1=0,c2=0,c3=0,c4=0;
	for(i=0;i<len;i++)
	{
		if(s[i]=='R')
			c1++;
		else if(s[i]=='G')
			c2++;
		else if(s[i]=='B')
			c3++;
		else if(s[i]=='W')
			c4++;
	}
	int check = 0;
	if(c1%2==0 && c2%2==0 && c3%2==0 && c4%2==0)
		check = 1;
	printf("%s\n",check?"YES":"NO");
	}
	return 0;
}
