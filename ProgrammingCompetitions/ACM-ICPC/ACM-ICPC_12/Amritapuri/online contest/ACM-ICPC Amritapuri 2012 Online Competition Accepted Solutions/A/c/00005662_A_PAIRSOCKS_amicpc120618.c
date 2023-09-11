#include <stdio.h>
#include <string.h>

int main()
{
	int total , R=0 ,G=0 , B=0 , W=0 , i , flag;
	char c , string[51];
	scanf("%d" , &total);
	scanf("%c" , &c);
	while(total--)
	{
	//	scanf("%s" , string);
	//	for(i=0 ; i< strlen(string) ; i++)
	//	{
		flag = 1;
		R = 0;
		G = 0;
		B = 0;
		W = 0;
		
		while(flag)
		{
			scanf("%c" , &c);
			switch(c)
			{
				case 'R' : 
					R++;
					break;
				case 'G' : 
					G++;
					break;
				case 'B' : 
					B++;
					break;
				case 'W' : 
					W++;
					break;
				default : 
					flag = 0;
					break;
				
			}
		}
		//printf("%d %d %d %d" , R, G  ,B ,W);
		if((R % 2 == 0 )&& (G % 2 == 0 )&& (B % 2 == 0 ) && (W % 2 == 0 ) )
			printf("YES\n");
		else
			printf("NO\n");
	//	}
	}
	return 0;
}
