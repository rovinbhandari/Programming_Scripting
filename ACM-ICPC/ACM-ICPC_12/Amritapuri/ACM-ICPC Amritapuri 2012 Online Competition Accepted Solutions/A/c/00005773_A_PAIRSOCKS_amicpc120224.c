#include<stdio.h>

int main()
{
	int t,i,j=0,r=0,g=0,b=0,w=0;
	char input[51],output[1001];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s",input);
		while(input[j]!='\0')
		{
			if(input[j]=='R')r++;
			if(input[j]=='G')g++;
			if(input[j]=='B')b++;
			if(input[j]=='W')w++;
			j++;
		}
		if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
			output[i]='Y';
		else
			output[i]='N';
		r=g=b=w=j=0;
	}
	for(i=0;i<t;i++)
	{
		if(output[i]=='Y')
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

