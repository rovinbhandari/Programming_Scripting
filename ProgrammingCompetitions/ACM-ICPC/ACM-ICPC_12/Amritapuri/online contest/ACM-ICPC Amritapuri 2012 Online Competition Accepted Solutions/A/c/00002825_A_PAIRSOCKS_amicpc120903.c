#include<stdio.h>
#include<string.h>

int main()
{
	int t,i,r,g,b,w;
	char ch[50],c;
	scanf("%d",&t);
	scanf("%c",&c);;
	while(t>0)
	{
		gets(ch);
		i=strlen(ch)-1;
		r=0;
		b=0;
		g=0;
		w=0;
		while(i>=0)	
		{
			if(ch[i]=='R')
				r++;
			else if(ch[i]=='B')
				b++;
			else if(ch[i]=='G')
				g++;
			else
				w++;			
			i--;
		}
		if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
			printf("YES\n");
		else
			printf("NO\n");	
		t--;
	}
	return 0;
}
