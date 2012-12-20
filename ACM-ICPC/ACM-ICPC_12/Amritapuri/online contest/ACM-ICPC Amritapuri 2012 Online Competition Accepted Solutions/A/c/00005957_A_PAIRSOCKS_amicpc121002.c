#include<stdio.h>
#include<ctype.h>

int main()
{
	int t,r=0,g=0,b=0,w=0;
	char s[50];
	int i=0;
	scanf("%d",&t);

	while(t--)
	{

		scanf("%s",s);
		i=0;
		r=0;
		g=0;
		b=0;
		w=0;
		while(s[i]!='\0')
		{
			switch(toupper(s[i]))
			{
				case 'R':
						r++;
						break;

				case 'B':
						b++;
						break;
				case 'G':
						g++;
						break;

				case 'W':
						w++;
						break;
			}
			i++;
		}

		if(r%2==0 && b%2==0 && w%2==0 && g%2==0)
			printf("YES\n");
		else
		{
			printf("NO\n");
		}


	}

	return 0;
}
