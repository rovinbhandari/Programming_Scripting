#include <stdio.h>

void reverse(int* a, int beg, int end)
{
	int i, temp;
	for(i = beg; i <= (beg + end) / 2; i++)
	{
		temp = a[i];
		a[i] = a[end - i + beg];
		a[end - i + beg] = temp;
	}
}

void rightrotate(int* a, int lena)
{
	reverse(a, 0, lena - 1);
	reverse(a, 1, lena - 1);
}

void output(int* a, int lena)
{
	int i;
	for(i = 0; i < lena; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(void)
{
	int a[] = {6, 2, 4, 1, 0, 84, 3};
	int lena = sizeof(a) / sizeof(int);
	
	//printf("Size of a = %d\n", lena);
	
	printf("Originally, a = ");
	output(a, lena);
	
	//reverse(a, 0, lena - 1);
	//printf("Reversed a = ");
	//output(a, lena);
	
	//reverse(a, 0, lena - 1);
	//printf("After 2 reversals, a = ");
	//output(a, lena);
	
	rightrotate(a, lena);
	printf("After 1 right-rotation, a = ");
	output(a, lena);
	
	rightrotate(a, lena);
	printf("After 2 right-rotations, a = ");
	output(a, lena);
	
	return 0;
}

