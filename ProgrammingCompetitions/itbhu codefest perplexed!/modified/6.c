#include <stdio.h>
main()
{
	int a,b,c,d,t;
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%d", &x);
		for(a=1;a<=x;a++)
			for(b=2;b<=x;b++)
				for(c=3;c<=x;c++)
					for(d=4;d<=x;d++)
						if(x-a-b-c-d > 4)
							n++;
		printf("%d\n", n));
	}
}

