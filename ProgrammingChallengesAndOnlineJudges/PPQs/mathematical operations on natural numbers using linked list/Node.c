#include <Node.h>
#include <stdlib.h>
#include <stdio.h>

static const size_t sizenode = sizeof(struct node);

struct node* newnode(struct data* pd, struct node* pn)
{
	struct node* n = (struct node*) malloc(sizenode);
	n->pdata = pd;
	n->pnext = pn;
	return n;
}

void editdata(struct node* pn, struct data* pd)
{
	pn->pdata = pd;
}

void outputnode(struct node* pn)
{
	printf("Contents of node %p:\t", (void*) pn);
	outputdata(pn->pdata);
	printf("\n");
}

// other function definitions.

