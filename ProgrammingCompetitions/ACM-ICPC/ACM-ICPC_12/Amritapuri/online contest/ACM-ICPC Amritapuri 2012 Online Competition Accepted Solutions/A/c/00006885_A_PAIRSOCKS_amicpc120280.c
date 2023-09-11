#include<stdio.h>
#include<string.h>
int main()
{
	char inp[50];
	int i,j,n,r,g,b,w;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",inp);
		r=0;g=0;b=0;w=0;
		for(j=0;j<strlen(inp);j++)
		{
			switch(inp[j])
			{
				case 'R':
					r++;
					break;
				case 'G':
					g++;
					break;
				case 'B':
					b++;
					break;
				case 'W':
					w++;
					break;
			}
		}	
		if(r%2==0 && g%2==0 && b%2==0 && w%2==0 && (r!=0 ||  g!=0 || b!=0 || w!=0) )
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
