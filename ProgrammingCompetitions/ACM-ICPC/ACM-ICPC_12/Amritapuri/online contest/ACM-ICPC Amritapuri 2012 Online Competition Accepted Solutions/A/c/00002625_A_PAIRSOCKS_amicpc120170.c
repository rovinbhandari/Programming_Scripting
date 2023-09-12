#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t;
	scanf("%d",&t);
	char inp;
	scanf("%c",&inp);
	while(t--){
		int r=0,g=0,w=0,b=0;
		while(scanf("%c",&inp)){
			if(inp=='\n')
				break;
			if(inp=='R')
				r++;
			else if(inp=='W')
				w++;
			else if(inp=='G')
				g++;
			else if(inp=='B')
				b++;
		}
		if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
