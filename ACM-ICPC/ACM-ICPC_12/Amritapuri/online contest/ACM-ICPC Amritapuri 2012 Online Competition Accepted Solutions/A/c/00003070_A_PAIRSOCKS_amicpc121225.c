#include<stdio.h>
#include<string.h>

int main()
{
	char sox[50];
	int len,ss[4],i,j,flag=0,T,k;
	scanf("%d",&T);
	for(j=0;j<T;j++)
	{
		scanf("%s",sox);
		for(k=0;k<4;k++)
			ss[k]=0;
		len=strlen(sox);
		for(i=0;i<len;i++)
		{
			if(sox[i]=='R')
			{
				ss[0]=ss[0]+1;
			}
			else if(sox[i]=='G')
			{
				ss[1]=ss[1]+1;
			}

			else if(sox[i]=='B')
			{
				ss[2]=ss[2]+1;
			}

			else if(sox[i]=='W')
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
