#include<stdio.h>
int main()
{
	int a[100][100], b[100][100], k, n, i, j;
	printf("\nEnter size of square matrix\n");
	scanf("%d", &n);
	printf("\nEnter the elements of the matrix\n");
	for(i=0; i < n; i++)
	{	
		printf("\nROW %d\n\t", i + 1);
		for(j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			printf("\n\t");
		}
	}
	printf("\nThe matrix A is : \n");
	for(i = 0; i < n; i++)
        {
		for(j = 0; j < n; j++)
                {
		        printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\nTranspose of A is : \n");
	for(i = 0; i < n; i++)
        {
		for(j=0;j<n;j++)
                {
		        printf("%d ",a[j][i]);
		}
		printf("\n");
	}
	for(i = 0; i < n; i++)
	{
		for(k = 0; k < n; k++)
                {	
			b[i][k]=0;
			for(j = 0; j < n; j++)
                	{	
				b[i][k] += a[i][j] * a[j][k];
			}
		}
	}
	printf("\n\nA*A^T =\n");
	for(i = 0; i < n; i++)
        {
		for(j = 0; j < n; j++)
                {
		        printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(((i == j) && (!(a[i][j] == 1))) || ((i != j) && (!(a[i][j] == 0))))
			{
				printf("\n\tThus A is NOT ORTHOGONAL\n\n");
				return(0);
			}
		}
	}
	printf("\n\tThus A is ORTHOGONAL\n\n");
}
