#ifndef NODE_H
#define NODE_H

#include <Data.h>

typedef struct node
	{
		struct data* pdata;
		struct node* pnext;
		// other struct members
	}
	Node;

// function declarations for converting to and from Node.

#endif

