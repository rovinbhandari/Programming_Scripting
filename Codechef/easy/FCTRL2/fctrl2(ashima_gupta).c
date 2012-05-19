#include <stdio.h>

int a[200];

int main()
{
	int temp,n[200],index,m=0,num,i,num2[200],j,x,k;
	scanf("%d",&num);
	for(k=1;k<=num;k++)
	{
		scanf("%d",&n[k-1]);
		num2[k-1]=n[k-1];
	}
	for(k=1;k<=num;k++)
	{
		temp=0;
		index=0;
		m=0;
		for(i=0;i<200;i++)
			a[i]=0;
		while(n[k-1]>0)
		{
			a[index]=n[k-1]%10;
			index++;
			m++;
			n[k-1]=n[k-1]/10;
		}
		for(i=1;i<num2[k-1];i++)
		{
			index=0;
			for(j=0;j<m;j++)
			{
				x=a[index]*i+temp;
				a[index]=x%10;
				index++;
				temp=x/10;
			}
			while(temp>0)
			{
				a[index]=temp%10;
				index++;
				temp=temp/10;
				m++;
			}
		}
		for(i=m-1;i>=0;i--)
			printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
