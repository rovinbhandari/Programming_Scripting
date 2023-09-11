#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int i,t,r,g,b,w;
	char a[100];
	scanf("%d",&t);
	while(t--)
	{
		r=g=b=w=0;
		scanf("%s",a);
		for(i=0;a[i]!=0;i++)
		{
			if(a[i]=='R')
				r++;
			else if(a[i]=='G')
				g++;
			else if(a[i]=='B')
				b++;
			else if(a[i]=='W')
				w++;
		}
		if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
