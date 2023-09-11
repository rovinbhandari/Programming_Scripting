#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n;
	int r,g,b,w;
	char v[100];
	char *c;
	scanf ("%d", &n);
	while (n--)
	{
		r = g = b = w = 0;
		scanf ("%s", v);
		c = v;
		while (*c != '\0')
		{
			if (*c == 'R')
				r = 1 -r;
			else if (*c == 'G')
				g = 1 - g;
			else if (*c == 'B')
				b = 1 - b;
			else if (*c == 'W')
				w = 1 - w;
			else;
			c++;
		}
		if (r + g + b + w == 0)
			printf ("YES\n");
		else
			printf("NO\n");
	}
	return 0;

}
