#include<stdio.h>
#include<string.h>

int main()
{
	char socks[50];
	int len,ss[4],i,j,flag=0,T,k;
	scanf("%d",&T);
	for(j=0;j<T;j++)
	{
		scanf("%s",socks);
		for(k=0;k<4;k++)
			ss[k]=0;
		len=strlen(socks);
		for(i=0;i<len;i++)
		{
			if(socks[i]=='R')
			{
				ss[0]=ss[0]+1;
			}
			else if(socks[i]=='G')
			{
				ss[1]=ss[1]+1;
			}

			else if(socks[i]=='B')
			{
				ss[2]=ss[2]+1;
			}

			else if(socks[i]=='W')
			{
				ss[3]=ss[3]+1;
			}

		}
		flag=0;
		for(i=0;i<4;i++)
		{
			if(ss[i]%2==1)
			{
				printf("NO\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("YES\n");
	}
	return 0;
}
