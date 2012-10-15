#include <LinkedList.h>
#include <stdio.h>
#include <stdlib.h>

struct node* gethead(struct linkedlist* pll)
{
	return pll->phead;
}

struct node* gettail(struct linkedlist* pll)
{
	return pll->ptail;
}

struct node* getcurrent(struct linkedlist* pll)
{
	return pll->pcurrent;
}

void setcurrent(struct linkedlist* pll, struct node* pn)
{
	pll->pcurrent = pn;
}

struct linkedlist* newlist()
{
	struct linkedlist* pll = (struct linkedlist*) malloc(sizeof(struct linkedlist));
	pll->phead = pll->ptail = pll->pcurrent = NULL;
	return pll;
}

void insertfrontmost(struct linkedlist* pll, struct data* pd)
{
	struct node* pn = newnode(pd, NULL);
	if(pll->phead)
	{
		pn->pnext = pll->phead;
		pll->phead = pll->pcurrent = pn;
	}
	else
		pll->phead = pll->ptail = pll->pcurrent = pn;
}

void insertbackmost(struct linkedlist* pll, struct data* pd)
{
	struct node* pn = newnode(pd, NULL);
	if(pll->ptail)
	{
		//TODO: can the following two statements be combined into one safely?
		pll->ptail->pnext = pn;
		pll->ptail = pn;
	}
	else
		pll->phead = pll->ptail = pll->pcurrent = pn;
}

void insertback(struct linkedlist* pll, struct data* pd)
{
	struct node* pn = newnode(pd, NULL);
	if(pll->pcurrent)
	{
		pn->pnext = pll->pcurrent->pnext;
		//TODO: can the following two statements be combined into one safely?
		pll->pcurrent->pnext = pn;
		pll->pcurrent = pn;
	}
	else if(pll->phead || pll->ptail)
	{
		fprintf(stderr, "pcurrent has been explicitly set to NULL while the linked list has a finite size.\n");
		exit(1);
	}
	else
		pll->phead = pll->ptail = pll->pcurrent = pn;
}

void outputlist(struct linkedlist* ll)
{
	printf("Contents of linked list %p:\n", (void*) ll);
	struct node* pn = ll->phead;
	while(pn)
	{
		printf("\t");
		outputnode(pn);
		pn = pn->pnext;
	}
	printf("=========================\n\n");
}

// other function definitions.

