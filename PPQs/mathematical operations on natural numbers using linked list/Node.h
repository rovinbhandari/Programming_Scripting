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

struct node* newnode(struct data*, struct node*);
// other function declarations.

#endif

