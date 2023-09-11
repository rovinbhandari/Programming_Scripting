#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r, g, b, w;
	int T, i, j;
	char in[50];
	scanf("%d", &T);

	for(i=0;i<T;i++)
	{
		scanf("%s",in);
		r=0;
		g=0;
		b=0;
		w=0;
		j = 0;
		while(in[j]!='\0')
		{
			if(in[j]=='R')
			{
				if(r==0)
					r = 1;
				else
					r=0;
			}
			else if(in[j]=='G')
			{
				if(g==0)
					g = 1;
				else
					g=0;
			}
			else if(in[j]=='B')
			{
				if(b==0)
					b = 1;
				else
					b=0;
			}
			else if(in[j]=='W')
			{
				if(w==0)
					w = 1;
				else
					w=0;
			}
			else
			{
				r=-1; 
				b=-1;
				g=-1;
				w=-1;
				j++;
				break;
			}
			in[j] = '\0';
			j++;
		}
		if(r==0&&b==0&&g==0&&w==0)
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
