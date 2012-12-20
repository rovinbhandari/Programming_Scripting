#include <stdio.h>

int main(void)
{
	
	int i, t;
	char c;
	
	int r, g, b, w;
	
	
	scanf("%d", &t);
	c = getchar();
	
	for(i=0; i<t; i++)
	{
		
		r = 0;
		g = 0;
		b = 0;
		w = 0;
		
		while((c = getchar()) != '\n')
		{
			if(c == 'R')
				r = 1 - r;
			else if (c == 'G')
				g = 1 - g;
			else if(c == 'B')
				b = 1 - b;
			else
				w = 1 - w;
		}
		
		if(r + g + b + w == 0)
			printf("YES\n");
		else
			printf("NO\n");
			
	}
	
	return 0;
	
}
