#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[1001];
		int R=0,G=0,B=0,W=0;
		scanf("%s",str);
		for(int i=0;str[i]!='\0';i++)
		{
			if(str[i]=='R')R++;
			else if(str[i]=='G')G++;
			else if(str[i]=='B')B++;
			else if(str[i]=='W')W++;
		}
		if((R&1) || (G&1) || (B&1) || (W&1))
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
