#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n,i=0;
	int r,g,b,w;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		char inp[60];
		scanf("%s",inp);
		r=0;
		g=0;
		b=0;
		w=0;
		int j=0;
		for(j=0;j<strlen(inp);j++)
		{
			if(inp[j]=='R')
			{
				r++;
			}
			else if(inp[j]=='G')
			{
				g++;
			}
			else if(inp[j]=='B')
			{
				b++;
			}
			else if(inp[j]=='W')
			{
				w++;
			}
		}
		if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}


