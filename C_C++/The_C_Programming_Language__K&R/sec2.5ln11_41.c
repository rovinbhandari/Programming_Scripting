#include <stdio.h>

#define	tprint(expr)	printf(#expr " = %g\n", (double) expr)

int main(void)
{
	// TODO:direction of truncation for / for negative operands
	/*
	tprint(((33.0) / (2)));
	tprint(((-33.0) / (2)));
	tprint(((33.0) / (-2)));
	tprint(((-33.0) / (-2)));
	tprint(((34.0) / (6)));
	tprint(((-34.0) / (6)));
	tprint(((34.0) / (-6)));
	tprint(((-34.0) / (-6)));
	*/

	printf("sign of the result for \% for negative operands\n");	// why the garbage value here?
	tprint(((33) % (2)));
	tprint(((-33) % (2)));
	tprint(((33) % (-2)));
	tprint(((-33) % (-2)));
	tprint(((34) % (6)));
	tprint(((-34) % (6)));
	tprint(((34) % (-6)));
	tprint(((-34) % (-6)));
	printf("It seems that for a \% b, the quotient is n such that |bn| < |a| and |b(n + 1)| > |a|, and the answer is: a - bn\n");
	
	return 0;
}
