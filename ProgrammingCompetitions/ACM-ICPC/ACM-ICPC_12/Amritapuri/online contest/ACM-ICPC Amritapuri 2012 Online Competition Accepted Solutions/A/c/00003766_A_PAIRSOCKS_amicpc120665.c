#include<stdio.h>
#define s(a) scanf("%d",&a);
#define p(a) printf("%c",a);

int main()
{
	int t,i;
	char sock[51];
	int r = 0;	
	int g = 0;
	int b = 0;	
	int w = 0;	
	s(t);
	getchar();
	while(t--)
	{
		r = g = b = w = 0;
		scanf("%s",sock);
		i = 0;
		while(sock[i]!='\0')
		{
			if(sock[i]=='R')
			{
				r = ~r;	
			}
			else if(sock[i]=='G')
			{
				g = ~g;	
			}
			else if(sock[i]=='B')
			{
				b = ~b;	
			}
			else if(sock[i]=='W')
			{
				w = ~w;	
			}
			i++;
		}
		if((!r)&(!g)&(!b)&(!w))
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
