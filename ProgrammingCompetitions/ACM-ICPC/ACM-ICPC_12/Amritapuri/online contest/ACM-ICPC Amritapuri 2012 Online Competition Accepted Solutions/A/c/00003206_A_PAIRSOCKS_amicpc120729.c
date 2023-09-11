#include<stdio.h>

int main()
{
	int tcases;
	scanf("%d",&tcases);

	int i=0,index=0;
	char a[60];
	int r=0,g=0,b=0,w=0;
	for(i=0; i<tcases; i++)
 	{
		scanf("%s",a);
		//printf("%s\n",a);
		
		index=0;
		while(a[index]!='\0')
		{
			if(a[index]=='R')	r++;
			if(a[index]=='G')	g++;
			if(a[index]=='B')	b++;
			if(a[index]=='W')	w++;

			index++;
		}

		if( (r%2==0) && (g%2==0) && (b%2==0) && (w%2==0) )	
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}

		r=0;g=0;b=0;w=0;
	}
	
	return 0;
}
