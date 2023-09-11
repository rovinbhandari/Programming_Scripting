#include<cstdio>
#include<iostream>

using namespace std;

int main()

{
	int t;
	scanf("%d",&t);
	
	char st[100];
	while(t--)
	{
		int r=0;
		int g=0,b=0,w=0;
		scanf("%s",st);
		char *p;
		p=st;
		while(*p!='\0')
		{
			if(*p=='R')
				r++;
			else if(*p=='G')
				g++;

			else if(*p=='B')
				b++;



			else if(*p=='W')
				w++;
			
				p++;

		}
		if( r%2 || g%2  || w%2 || b%2)
		{
			printf("NO\n");
		}
		else 
			printf("YES\n");
	}
	return 0;

}

