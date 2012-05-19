#include<stdio.h>
int main()
{
	int i, j, n, flag=0;
	printf("\n\tEnter size of matrix : ");
	scanf("%d", &n);
	float arr[n][n];
	printf("\n\tEnter matrix\n");
	for(i = 0; i < n; i++)
	{
		printf("\nEnter row %d : \n",i+1);
		for(j = 0; j < n; j++)
		{
			printf("\t\t\t");
			scanf("%f", &arr[i][j]);
			if(i > j)
			{
				if(arr[i][j] != 0.0)
				{	
					flag = 1;
				}
			}
		}	
	}
	printf("\n\n\t The matrix is \n\n");
	for(i = 0; i < n; i++)
	{      	 
		for(j = 0; j < n; j++)       
        	{
		  	 printf("%f ", arr[i][j]);
		}
		printf("\n");
	}
	if(flag == 1)
	{
		printf("\n\t It is NOT an Upper Triangular matrix\n\n");
	}
	else
	{
		printf("\n\t It is an Upper Triangular matrix\n\n");
	}
}
