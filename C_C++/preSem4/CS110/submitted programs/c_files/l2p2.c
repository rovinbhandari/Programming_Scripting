#include<stdio.h>
int main()
{
	int i, j, k;
	printf("\n\tThe reqiured pattern is:\n\n");
	for(i = 0; i < 6; i++)				//	"i" changes the row in which printing is taking place 
	{
		printf("\t ");
		for(k = 0; k < i; k++)			//	"k" prints the spaces in front of the first number printed
		{
			printf("  ");
		}
		for(j = 10; j > 5 + i; j--)		//	"j" here prints numbers in front of "5"
		{
			printf("%d ", j);
		}
		if(i != 5)				//	The if-else blocks print each "5" with proper indentation
		{
			printf("5 ");
		}
		else
		{
			printf(" 5 ");
		}
		for(j = 4 - i; j >= 0; j--)		//	"j" here prints numbers ahead of "5"
		{	
			printf("%d ", j);
		}
		printf("\n");				//	The cursor goes to the next line after printing is complete in the current row
	}
}
	
