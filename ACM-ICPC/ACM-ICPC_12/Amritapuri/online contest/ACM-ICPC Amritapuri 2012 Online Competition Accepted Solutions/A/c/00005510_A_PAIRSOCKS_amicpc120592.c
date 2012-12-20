#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char colors[50];
int counter[4];
int main()
{
	int t=0;
	int i=0,j=0,c=0;
	scanf("%d", &t);
	while(t--)
	{
		
			scanf("%s", colors);
			while(i<strlen(colors))
			{
	
				if(colors[i]=='R')
					counter[0]++;
				else if(colors[i]=='G')
					counter[1]++;
				else if(colors[i]=='B')
					counter[2]++;
				else if(colors[i]=='W')
					counter[3]++;
				i++;
			}
		
		for(j=0;j<4;j++)
		{
	//		printf("%d\t", counter[j]);
			if(counter[j]%2==1)
				c=1;
		}
		if(c==1)
			printf("NO\n");
		else
			printf("YES\n");
	
		c=0;i=0;
		for(j=0;j<4;j++)
			counter[j]=0;
			
	}
	return 0;	
}



