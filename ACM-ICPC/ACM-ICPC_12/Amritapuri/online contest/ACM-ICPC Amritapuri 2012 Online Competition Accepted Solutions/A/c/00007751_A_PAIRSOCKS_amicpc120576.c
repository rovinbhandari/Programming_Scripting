#include<stdio.h>
main()
{
	int t,r=0,g=0,b=0,w=0,i,j;
	char c[50],op[1000];
	scanf("%d",&t);
	for(i=0;i<t;++i)
	{
		r=0,g=0,b=0,w=0;
		scanf("%s",c);
		for(j=0;c[j]!='\0';++j)
		{
			if(c[j]=='R')
				r++;
			else if(c[j]=='G')
				g++;
			else if(c[j]=='B')
				b++;
			else if(c[j]=='W')
				w++;
			else
				return 0;
			c[j]='\0';
		}
		if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
			op[i]='Y';
			
		else
			op[i]='N';
	}
	for(i=0;i<t;++i)
	{
			if(op[i]=='Y')
				printf("YES\n");
			else
				printf("NO\n");
	}
	return 0;
}

