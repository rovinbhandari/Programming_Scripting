#include <operations.h>
#include <stdio.h>

int main(void)
{
	int a = 23, b = 11;
	LinkedList* lla = intnumbertolinkedlist(a);
	LinkedList* llb = intnumbertolinkedlist(b);
	LinkedList* llc = multiply(lla, llb);
	int c = linkedlisttointnumber(llc);
	printf("a = %d\nlla = ", a);
	outputlist(lla);
	printf("b = %d\nllb = ", b);
	outputlist(llb);
	printf("llc = ");
	outputlist(llc);
	printf("c = %d\n", c);
	return 0;
}

