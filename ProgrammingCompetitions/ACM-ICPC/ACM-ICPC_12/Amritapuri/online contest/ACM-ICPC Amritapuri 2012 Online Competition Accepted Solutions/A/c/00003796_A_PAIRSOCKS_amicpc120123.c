#include<stdio.h>
#include<string.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		getchar();
		int f=0;
		char str[100];
		int r=0 , b=0 , g=0, w=0;
		scanf("%[^\n]",str);
		int l = strlen(str);
		if(l%2 == 1)
		{
			printf("NO\n");
			continue;
		}
		int i=0;
		for(i=0; i<l; i++)
		{
			if(str[i] == 'R')
				r++;
			if(str[i] == 'G')
				g++;
			if(str[i] == 'W')
				w++;
			if(str[i] == 'B')
				b++;
		}
		if( (r%2 == 0) && (b%2 == 0) && (w%2 == 0) && (g%2 == 0) )
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
