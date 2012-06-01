#include <operations.h>
#include <stdio.h>

int main(void)
{
	int a = 15382, b = 6914;
	printf("a = %d\nlla = ", a);
	printf("b = %d\nllb = ", b);
	LinkedList* lla = intnumbertolinkedlist(a);
	outputlist(lla);
	LinkedList* llb = intnumbertolinkedlist(b);
	outputlist(llb);

	LinkedList* llc = add(lla, llb);
	printf("llc = ");
	outputlist(llc);
	int c = linkedlisttointnumber(llc);
	printf("c = %d\n", c);
	
	LinkedList* lld = subtract(lla, llb);
	printf("lld = ");
	outputlist(lld);
	int d = linkedlisttointnumber(lld);
	printf("d = %d\n", d);
	
	return 0;
}

