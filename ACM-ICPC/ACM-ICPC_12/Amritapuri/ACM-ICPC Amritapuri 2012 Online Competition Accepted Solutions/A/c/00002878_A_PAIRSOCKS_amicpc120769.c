#include<stdio.h>

int main()
{
	int t,r,g,b,w,i;
	char a[51];
	scanf("%d",&t);
	while(t--)
	{
		r=0;
		g=0;
		b=0;
		w=0;
		scanf("%s",a);
		i=0;
		while(a[i]!='\0')
		{
		if(a[i]=='R') r++;
		if(a[i]=='G') g++;
		if(a[i]=='B') b++;
		if(a[i]=='W') w++;
		i++;
		}
		if((r%2)==0 && (g%2)==0 && (b%2)==0 && (w%2)==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
