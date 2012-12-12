#include <stdio.h>
int main()
{
	int i, j, t;
	scanf("%d", &t);
	int results[1000];
	char str[51];
	int r,b,g,w;
	for(i=0; i<t; i++)
	{
		int sum=0;
		scanf("%s", str);
		r=0;b=0;g=0;w=0;
		for(j=0; str[j]!='\0'; j++)
		{
			if(str[j]=='R')
				r++;
			if(str[j]=='G')
				g++;
			if(str[j]=='B')
				b++;
			else
				w++;
							
		}
		if((r % 2 ==0) && (b % 2 ==0) && (g % 2 ==0) && (w % 2 ==0) )			
		 	results[i]=0;
		else
		 	results[i]=1;			 
	}
	for(i=0; i<t; i++)
	{
		if(results[i]==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
