#include <Data.h>
#include <stdlib.h>
#include <assert.h>

// function definitions for converting to and from Data.
struct data* digittodata(int x)
{
	assert(x >= 0 && x <= 9);
	struct data* d = (struct data*) malloc(sizeof(struct data));
	d->digit = x;
	return d;
}

Digit datatodigit(struct data* d)
{
	return d->digit;
}

