#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char str[100];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r=0,b=0,g=0,w=0;
		scanf("%s",str);
		for(int i=0;i<strlen(str);i++)
		{
			char x=str[i];
			if(x=='R')
			r=r+1;
			if(x=='G')
			g=g+1;
			if(x=='B')
			b=b+1;
			if(x=='W')
			w=w+1;
		}
		if((((r%2)==0)&&((g%2)==0)&&((b%2)==0)&&((w%2)==0)))
		printf("YES");
		else
		printf("NO");
		printf("\n");
	}
	return 0;
}
