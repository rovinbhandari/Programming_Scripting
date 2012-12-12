#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,n,r,g,b,w;
	char **s;
	scanf("%d",&n);
	s=(char**)malloc(sizeof(char*)*n);
	for(i=0;i<n;i++)
	{
		s[i]=(char*)malloc(sizeof(char)*50);
	}
	i=0;
	
	while(i<n)
	{
		scanf("%s",s[i]);
		i++;
	}
	
	for(i=0;i<n;i++)
	{
		r=0;g=0;b=0;w=0;
	for(j=0;j<50;j++)
	{
		if(s[i][j]=='R')
		{
			r++;continue;
		}
		if(s[i][j]=='G')
		{
			g++;continue;
		}
		if(s[i][j]=='B')
		{
			b++;continue;
		}
		if(s[i][j]=='W')
		{
			w++;continue;
		}
	}
	
	if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
	{
		printf("YES\n");
	}
	else
	printf("NO\n");
	}
return 0;
}
