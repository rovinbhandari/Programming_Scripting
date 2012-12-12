#include <stdio.h>

int main()
{
	register int r,g,b,w,i;
	int t;
	char arr[52];
	
	scanf("%d",&t);
	while(t--)
	{
		r=g=b=w=0;
		
		scanf("%s",arr);
		for(i=0;arr[i]!='\0';i++)
		{
			switch(arr[i])
			{
				case 'R' : r++;
							break;
				case 'G' : 	g++;
							break;
				case 'B' : b++;
							break;
				case 'W' : w++;
							break;
			}
			
		}
	
		if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
		printf("YES\n");
		else
		printf("NO\n");
	
	}
	return 0;
}
