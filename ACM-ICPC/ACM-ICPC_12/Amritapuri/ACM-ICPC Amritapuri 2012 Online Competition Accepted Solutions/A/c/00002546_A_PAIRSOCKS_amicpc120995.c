#include <stdio.h>

int main(int argc, char **argv)
{
	int i,t,r,g,b,w;
	char str[1000];
	scanf("%d",&t);
	while(t--)
	{
		r=g=b=w=0;
		scanf("%s",str);
		for(i=0; str[i]; i++)
		{
			if(str[i] == 'R')
			{
				r++;
			}
			else if(str[i] == 'G')
			{
				g++;
			}
			else if(str[i] == 'B')
			{
				b++;
			}
			else if(str[i] == 'W')
			{
				w++;
			}
		}
		
		if(r%2==0 &&g%2==0 &&b%2==0 &&w%2==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

