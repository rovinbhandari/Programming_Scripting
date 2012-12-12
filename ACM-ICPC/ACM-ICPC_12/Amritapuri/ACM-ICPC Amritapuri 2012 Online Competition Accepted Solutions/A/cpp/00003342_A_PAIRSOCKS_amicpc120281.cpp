#include<stdio.h>
#include<string.h>
int main()
{
	char str[53];
	int tc,r,g,b,w;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%s",str);
		r=g=b=w=0;
		int l=strlen(str);
		for(int i=0;i<l;i++)
		{
			if(str[i]=='B')
				b++;
		        else if(str[i]=='R')
				r++;
		        else if(str[i]=='G')
				g++;
		        else if(str[i]=='W')
				w++;
		}
		if((w%2)||(g%2)||(b%2)||(r%2))
			printf("NO\n");
		else
			printf("YES\n");
		 

	}
	return 0;
}
