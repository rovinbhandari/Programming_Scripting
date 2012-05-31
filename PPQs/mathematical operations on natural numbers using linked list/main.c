#include <operations.h>
#include <stdio.h>

int main(void)
{
	int a = 2389, b = 23484, c = linkedlisttointnumber(add(intnumbertolinkedlist(a), intnumbertolinkedlist(b)));
	printf("%d\n", c);
	return 0;
}

