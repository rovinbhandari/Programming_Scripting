#include<stdio.h>
int main()
	{
	char a[52];
	int i,j,t,flag=1;
	int count[4];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{ scanf("%s",&a);
	flag=1;
	for(j=0;j<4;j++)
	count[j]=0;
	for(j=0;j<strlen(a);j++)
		{
		if(a[j]=='R') count[0]++;
		if(a[j]=='G') count[1]++;
		if(a[j]=='B') count[2]++;
		if(a[j]=='W') count[3]++;
		}
	for(j=0;j<4;j++)
	if((count[j]%2)==1)
	flag=0;
	
	if(flag==0)
	printf("NO\n");
	else
	printf("YES\n");

	}

	return 0;
		
	}
