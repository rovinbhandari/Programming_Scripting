#include <stdio.h>

int main()
{
	char *p = "hello world";
	++*p;
	printf("%c", *p);
	return 0;
}
