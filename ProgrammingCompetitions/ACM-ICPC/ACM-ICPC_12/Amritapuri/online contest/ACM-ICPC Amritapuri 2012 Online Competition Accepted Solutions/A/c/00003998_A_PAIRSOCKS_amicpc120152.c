#include<stdio.h>
#include<stdlib.h>

int main ()
{
	char ch;

	int testit,test,i;
	char ans=0;
	scanf("%d",&test);

	for(testit=0 ;testit< test; testit++)

	{

		ans=0;
		scanf(" %c",&ch);

		while(ch!='\n')
		{

			if(ch=='R')
			{

				ans= ans^1;
			}

			else if (ch == 'B')	
				ans = ans^2;

			else if (ch == 'G' )
				ans= ans^4;

			else if(ch == 'W')
				ans = ans^8;

			scanf("%c",&ch);
		}
		if(ans==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}


	 
