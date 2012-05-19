#include<stdio.h>

void calc1(int b[][2])
{
	printf("in function calc1, size = %d", sizeof(b));
}

void calc2(int ** b)
{
	printf("in function calc2, size = %d", sizeof(b));
}

void main()
{
	int a1[][2] = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
	printf("in main, size = %d", sizeof(a1));
	printf("\n");
	calc1(a1);
	printf("\n");
	calc2(a1);
	printf("\n");
	
	int ** a2 = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
	printf("in main, size = %d", sizeof(a2));
	printf("\n");
	calc1(a2);
	printf("\n");
	calc2(a2);
	printf("\n");
}


/*
	OUTPUT:-
	(Why the warnings?)
	in main, size = 32
	in function calc1, size = 4
	in function calc2, size = 4
	in main, size = 4
	in function calc1, size = 4
	in function calc2, size = 4

	EXPLANATION:-
	
*/
