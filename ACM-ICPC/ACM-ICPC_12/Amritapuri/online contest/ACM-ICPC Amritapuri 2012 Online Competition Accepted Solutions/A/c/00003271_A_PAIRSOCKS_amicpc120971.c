#include<stdio.h>
int main()
{
	int test,a,i,j,k,count[4]={0,0,0,0},op[1002];
	char str[50];
	scanf("%d",&test);
	for(a=0;a<=test;a++)
	{
		gets(str);
		count[0]=count[1]=count[2]=count[3]=0;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]=='R')
				count[0]++;
			if(str[i]=='G')
				count[1]++;
			if(str[i]=='B')
				count[2]++;
			if(str[i]=='W')
				count[3]++;			
		}
		if(count[0]%2==0 && count[1]%2==0 && count[2]%2==0 && count[3]%2==0)
			op[a]=1;
		else
			op[a]=0;
	}
	for(a=1;a<=test;a++)
	{
		if(op[a]==1)
			printf("YES\n");
		else if(op[a]==0)
			printf("NO\n");
	}
	return 0;
}
