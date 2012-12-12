#include<stdio.h>
#include<string.h>

int main()
{
	int t;
	scanf("%d",&t);
	
	while(t>0)
	{
		int i,j;
		char s[52];

		scanf("%s",s);

		int len=strlen(s);

		int a[4]={0};

		for(i=0;i<len;i++)
		{
			if(s[i]=='R')
			{
				a[0]++;
			}
			else if(s[i]=='G')
			{
				a[1]++;

			}
			else if(s[i]=='B')
			{
				a[2]++;
			}
			else
			{
				a[3]++;
			}

		}
		int flag=1;

		for(i=0;i<4;i++)
		{
			if(a[i]%2!=0)
			{
				flag=0;
				break;
			}
			
		}

		if(flag==1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");

		}
		
		t--;
	}
	return 0;
}
