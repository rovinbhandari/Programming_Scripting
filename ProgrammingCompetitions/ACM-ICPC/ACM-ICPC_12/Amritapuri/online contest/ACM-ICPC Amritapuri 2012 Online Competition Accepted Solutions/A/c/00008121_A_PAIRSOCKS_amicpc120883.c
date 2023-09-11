#include<stdio.h>
#include<string.h>
int main()
{
	char a[51];
	int t,i,j,k,n,flag,count[4];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s",a);
		n=strlen(a);
		count[0]=0;
		count[1]=0;
		count[2]=0;
		count[3]=0;
		for(j=0;j<n;j++)
		{
			if(a[j]=='R')
			{
				count[0]++;
			 }
			 else if(a[j]=='G')
			 {
				count[1]++;
			 }
			 else if(a[j]=='B')
			 {
				count[2]++;
			 }
			 else if(a[j]=='W')
			 {
				count[3]++;
			 }
		}
		flag=0;
		for(j=0;j<4;j++)
		{
			if((count[j]%2)!=0)
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}
