// not complete yet

/*
	Do static arrays get initialized to all zero values like static variables?
	e.g.,
	
#include <stdio.h>
void foo(void)
{
static int a;
++a;
printf("%d\n", a);
}
int main(void)
{
foo();
foo();
foo();
}
	would print 1, 2 and 3.
*/
