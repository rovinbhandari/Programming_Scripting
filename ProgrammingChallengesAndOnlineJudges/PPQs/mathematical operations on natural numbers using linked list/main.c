#include <operations.h>
#include <stdio.h>

int main(void)
{
	int a = 23, b = 11;
	
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
	
	LinkedList* lle = multiply(lla, llb);
	printf("lle = ");
	outputlist(lle);
	int e = linkedlisttointnumber(lle);
	printf("e = %d\n", e);
	
	return 0;
}

