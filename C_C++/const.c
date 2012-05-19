/*
	Experiments with the "const" keyword
*/

#include <stdio.h>

#define	t(e)	printf(#e " = %d\n", e)
#define	y(p)	printf(#p " = %p\n", (void*) p)		// %p expects void* by the definition of C.

int main(void)
{
	int a = 84;
	const int b = 404;
	t(a);
	t(b);

	a++;
	//b++;		// not allowed by compiler. gives error.
	t(a);
	t(b);
	
	int* pa1 = &a;			// the pointer and the value it points to are both modifiable.
	const int* pa2 = &a;		// the pointer is modifiable here, but not the value that it points to.
	int* const pa3 = &a;		// the pointer is constant here, but not the value it points to.
	const int* const pa4 = &a;	// the pointer and the value it points to are both constant.
	y(pa1);
	y(pa2);
	y(pa3);
	y(pa4);

	++*pa1;		// *pa1++ would have incremented pa1 rather than the value it points to.
	t(*pa1);
	y(pa1);
	++pa1;
	t(*pa1);
	y(pa1);

	//++*pa2;	// compiler gives error here.
	t(*pa2);
	y(pa2);
	++pa2;
	t(*pa2);
	y(pa2);
	//++*pa2;	// compiler gives error here, because the new value it points to becomes read-only now.
	t(*pa2);
	y(pa2);

	++*pa3;
	t(*pa3);
	y(pa3);
	//++pa3;	// compiler gives error here.
	t(*pa3);
	y(pa3);

	//++*pa4;	// compiler gives error here.
	t(*pa4);
	y(pa4);
	//++pa4;	// compiler gives error here.
	t(*pa4);
	y(pa4);

	printf("\n");

	int* pb1 = &b;			// the compliler gives a warning here (initialization discards qualifiers from pointer target type) because the declaration of pb1 does not ensure that the value of b (which is a const itself) remains constant.
	const int* pb2 = &b;
	int* const pb3 = &b;		// the compliler gives a warning here (initialization discards qualifiers from pointer target type) because the declaration of pb3 does not ensure that the value of b (which is a const itself) remains constant.
	const int* const pb4 = &b;
	y(pb1);
	y(pb2);
	y(pb3);
	y(pb4);

	++*pb1;		// the value to which pb1 is pointing gets modified here => b gets modified (indirectly) by the use of pointers (though the compiler gives a warning for initializing that pointer).		//TODO: this results in "undefined behaviour by definition of C"; is it true?
	t(*pb1);
	t(b);
	y(pb1);
	++pb1;		// why does this make pb1 point to a ?
	t(*pb1);
	y(pb1);

	//++*pb2;	// compiler gives error here.
	t(*pb2);
	y(pb2);
	++pb2;		//TODO: why does this make pb2 point to a ?
	t(*pb2);
	y(pb2);
	//++*pb2;	// compiler gives error here, because the new value it points to becomes read-only now.
	t(*pb2);
	y(pb2);

	++*pb3;		// the value to which pb3 is pointing gets modified here => b gets modified (indirectly) by the use of pointers (though the compiler gives a warning for initializing that pointer).		// this results in "undefined behaviour by definition of C"; is it true?
	t(*pb3);
	y(pb3);
	//++pb3;	// compiler gives error here.
	t(*pb3);
	y(pb3);

	//++*pb4;	// compiler gives error here.
	t(*pb4);
	y(pb4);
	//++pb4;	// compiler gives error here.
	t(*pb4);
	y(pb4);

	printf("\n");
	
	const int* p1 = &b;
	int* p2 = &a;
	t(*p1);
	y(p1);
	t(*p2);
	y(p2);
	
	p1 = p2;	// this is allowed by the definition of C.
	t(*p1);
	y(p1);
	t(*p2);
	y(p2);
	
	//++*p1;	// the compiler gives an error here (duh!)
	t(*p1);
	y(p1);
	++p1;
	t(*p1);
	y(p1);

	p2 = p1;	// the compiler gives a warning here (because it doesn't ensure the value of what p1 points to be consant).
	t(*p1);
	y(p1);
	t(*p2);
	y(p2);

	++*p2;		// the behaviour of making a non-const pointer point to a const is definitely undefined. see const.c.png and check the last few lines. of this section: the pointer does not increment what it points to by 1 and ++p2 below increments it not by 4 but by 1!
	t(*p2);
	y(p2);
	++p2;
	t(*p2);
	y(p2);

	printf("\n");
	
	const int* p3 = &b;
	int* p4 = &a;
	t(*p3);
	y(p3);
	t(*p4);
	y(p4);

	p4 = (int*) p3;		// the compiler doesn't even show a warning here! But the behaviour is still undefined by the defnition of C.
	t(*p3);
	y(p3);
	t(*p4);
	y(p4);

	++*p4;
	t(*p4);
	y(p4);
	++p4;		//TODO: why does this make p4 point to a ?
	t(*p4);
	y(p4);

	printf("\n");
	
	//TODO: make a const int* pointer to a value. make an int** pointer to the previous pointer. increment the value pointed to by the former pointer.

	return 0;
}

