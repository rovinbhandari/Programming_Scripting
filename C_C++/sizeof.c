#include <stdio.h>

#define	p(e)	printf("sizeof(" #e ") = %d\n", sizeof(e))
#define	r(e)	printf("addressof(" #e ") = %p\n", (void*) (e))

struct A
{
	int a;
	int b;
	int c;
	int d;
};

struct B		// to check for byte alignment
{
	char a;
	int b;
	char c;
	int d;
};

struct C		// to check for bit alignment
{
	int a : 1;
	int b;
	int c : 2;
	int d;
};

struct C_1		// to check for bit alignment
{
	int a : 1;
	int a_1 : 1;
	int b;
	int c : 2;
	int d : 30;
};

struct D		// to check for bit alignment
{
	int a1 : 1;
	int a2 : 1;
	int a3 : 1;
	int a4 : 1;
	int a5 : 1;
	int a6 : 1;
	int a7 : 1;
	int a8 : 1;
	
	int a9 : 1;
	int a10 : 1;
	int a11 : 1;
	int a12 : 1;
	int a13 : 1;
	int a14 : 1;
	int a15 : 1;
	int a16 : 1;
};

struct E		// to check for bit alignment
{
	int a1 : 1;
	int a2 : 1;
	int a3 : 1;
	int a4 : 1;
	int a5 : 1;
	int a6 : 1;
	int a7 : 1;
	int a8 : 1;
	
	int a9 : 1;
	int a10 : 1;
	int a11 : 1;
	int a12 : 1;
	int a13 : 1;
	int a14 : 1;
	int a15 : 1;
	int a16 : 1;

	int a17 : 1;
};

struct F		// to check for bit alignment
{
	int a1 : 1;
	int a2 : 1;
	int a3 : 1;
	int a4 : 1;
	int a5 : 1;
	int a6 : 1;
	int a7 : 1;
	int a8 : 1;

	int a9 : 1;
	int a10 : 1;
	int a11 : 1;
	int a12 : 1;
	int a13 : 1;
	int a14 : 1;
	int a15 : 1;
	int a16 : 1;

	int a17 : 1;
	int a18 : 1;
	int a19 : 1;
	int a20 : 1;
	int a21 : 1;
	int a22 : 1;
	int a23 : 1;
	int a24 : 1;

	int a25 : 1;
	int a26 : 1;
	int a27 : 1;
	int a28 : 1;
	int a29 : 1;
	int a30 : 1;
	int a31 : 1;
	int a32 : 1;
};

struct G		// to check for bit alignment
{
	int a1 : 1;
	int a2 : 1;
	int a3 : 1;
	int a4 : 1;
	int a5 : 1;
	int a6 : 1;
	int a7 : 1;
	int a8 : 1;

	int a9 : 1;
	int a10 : 1;
	int a11 : 1;
	int a12 : 1;
	int a13 : 1;
	int a14 : 1;
	int a15 : 1;
	int a16 : 1;

	int a17 : 1;
	int a18 : 1;
	int a19 : 1;
	int a20 : 1;
	int a21 : 1;
	int a22 : 1;
	int a23 : 1;
	int a24 : 1;

	int a25 : 1;
	int a26 : 1;
	int a27 : 1;
	int a28 : 1;
	int a29 : 1;
	int a30 : 1;
	int a31 : 1;
	int a32 : 1;

	int a33 : 1;
};

int main(void)
{
	// primitive datatypes
	p(int);
	int q, w = 5;
	p(q);
	p(w);

	p(char);
	
	p(long);
	p(long long);
	//p(long long long);		// too long for GCC
	//p(long long long long);	// too long for GCC

	
	// pointers to primitive datatypes
	int* p1 = &q;
	p(p1);
	int* p2 = &w;
	p(p2);
	int* p7;
	p(p7);
	
	//XXX: important example below...
	char a = 'h';
	char* p3 = &a;
	p(*p3);
	int* p4 = (int*) p3;
	p(p4);
	p(*p4);
	// print addresses of p3 and p4 to check(confirm!) whether they reserve space at different places.	XXX: HOLY SHIT!
	r(&a);
	r(p3);
	r(p4);

	struct B* p5;
	p(p5);
	p(*p5);
	struct A a1;
	p(a1);

	p(char*);

	p(void*);

	p(NULL);


	// above structs
	struct A a2;
	p(a2);
	p(struct A);

	p(struct B);	//XXX: notice the byte alignment in play here.

	p(struct C);	//XXX: notice the bit alignment in play here.

	p(struct C_1);	//XXX: notice the bit alignment in play here.

	p(struct D);	//XXX: notice the bit alignment in play here.

	p(struct E);	//XXX: notice the bit alignment in play here.

	p(struct F);	//XXX: notice the bit alignment in play here.

	p(struct G);	//XXX: notice the bit alignment in play here.


	// arrays of primitive datatypes and strings
	int ar1[] = {4, 2, 7};
	p(ar1);		//XXX: important!
	p(ar1[2]);
	p(*ar1);
	
	/*
	r(ar1);
	ar1++;		// NOT ALLOWED.
	r(ar1);
	p(ar1);
	*/

	/*
	int e = 6;
	r(ar1);
	ar1 = &e;	// pointers CANNOT be assigned to arrays.
	r(ar1);
	p(ar1);
	p(*ar1);
	*/

	char ar2[] = "gg";
	p(ar2);
	p(ar2[1]);
	p(*ar2);

	int ar3[5] = {2, 3, 5};
	p(ar3);
	p(*(ar3 + 4));
	printf("*(ar3 + 4) = %d\n", *(ar3 + 4));

	/*
	r(ar1);
	ar1 = ar3;	// pointers CANNOT be assigned to arrays.
	r(ar1);
	p(ar1);
	p(*ar1);
	*/

	char ar4[6] = "foo";
	p(ar4);
	p(*(ar4 + 4));
	printf("*(ar4 + 4) = %d\n", *(ar4 + 4));	//XXX: inmportant!

	//XXX: important example below...
	int ar5[4][6][8] = {0};
	p(ar5);
	p(*ar5);
	p(**ar5);
	p(ar5[2]);
	p(ar5[2][3]);
	r(ar5);
	r(*ar5);
	r(**ar5);
	r(ar5[2]);
	r(ar5[2][3]);
	

	// pointers to arrays of primitive datatypes and strings
	int* par1 = ar1;
	p(par1);
	p(*par1);

	char* par2 = ar2;
	p(par2);
	p(*par2);


	// shift operators applied to chars (to check if a char is converted to an int on applying a shift operator)
	char c = 67;
	p(c);
	p(c << 1);	//XXX: important!


	return 0;
}

