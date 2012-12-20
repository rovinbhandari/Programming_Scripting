#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,t,r,b,g,w;
	char a[100];
	scanf("%d",&t);
	while(t--)
	{
		r=0;
		b=0;
		g=0;
		w=0;
		scanf("%s",a);
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]=='R')
			r=r+1;
			if(a[i]=='B')
			b=b+1;
			if(a[i]=='G')
			g=g+1;
			if(a[i]=='W')
			w=w+1;
		}
		if((r%2==0)&&(w%2==0)&&(g%2==0)&&(b%2==0))
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
