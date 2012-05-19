// this code has errors.

/*

int array[arraysize];
for(i = 0; i < arraysize; i++)
	array[i] = 0;

is equivalent to:

int array[arraysize] = {0};	// at the time of declaration

and/or

memset(array, 0, arraysize * sizeof(int));	// later on if required

*/

#include <stdio.h>

int x1d[5] = {0};
int y1d[5];

int x2d[5][10] = {0};
int y2d[5][10];

void printarray2d(int a[][10])
{
	int i = 0, j = 0;
	while(i < 5)
	{
		while(j < 10)
		{
			printf("%d\n", a[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void printarray1d(int a[])
{
	int i = 0;
	while(i < 5)
	{
		printf("%d\n", a[i]);
		i++;
	}
}

void main()
{
	printarray1d(x1d);
	printf("\n===\n");
	printarray1d(y1d);
	
	printf("\n===\n");
	printf("\n===\n");
	
	printarray2d(x2d);
	printf("\n===\n");
	printarray2d(y2d);
}
