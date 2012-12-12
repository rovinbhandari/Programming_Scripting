#include<stdio.h>
#include<string.h>
#define size 50

int main()
{

	int tcase,i,j;
	scanf("%d",&tcase);
	char input[size];
	int answer[tcase];
	for(i=0;i<tcase;i++)
	{
		int r=0,g=0,b=0,w=0;
		scanf("%s",input);
		for(j=0;input[j]!='\0';j++)
		{
			if(input[j]=='R')
				r++;
			if(input[j]=='G')
				g++;
			if(input[j]=='W')
				w++;
			if(input[j]=='B')
				b++;
		}
		if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
		{
			answer[i]=1;
		}
		else
			answer[i]=0;
	}	
	for(i=0;i<tcase;i++)
	{
		if(answer[i]==1)
			printf("YES\n");
		else
			printf("NO\n");
	}	
	return 0;
}
