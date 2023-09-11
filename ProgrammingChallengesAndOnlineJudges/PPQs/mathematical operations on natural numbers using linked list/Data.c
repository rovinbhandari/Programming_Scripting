#include <Data.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// function definitions for converting to and from Data.
struct data* inttodata(int x)
{
	assert(x >= 0 && x <= 9);
	struct data* d = (struct data*) malloc(sizeof(struct data));
	d->digit = x;
	return d;
}

Digit datatoint(struct data* d)
{
	return d->digit;
}

void outputdata(struct data* pd)
{
	printf("%d", datatoint(pd));
}

// other function definitions.

