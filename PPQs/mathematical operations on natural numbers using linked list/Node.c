#include <Node.h>
#include <stdlib.h>

static const size_t sizenode = sizeof(struct node);

struct node* newnode(struct data* pd, struct node* pn)
{
	struct node* n = (struct node*) malloc(sizenode);
	n->pdata = pd;
	n->pnext = pn;
	return n;
}

// other function definitions.

