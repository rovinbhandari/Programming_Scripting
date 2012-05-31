#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <Node.h>

typedef struct linkedlist
	{
		struct node* phead;
		struct node* ptail;
		struct node* pcurrent;
		// other struct members
	}
	LinkedList;

struct node* gethead(struct linkedlist*);
struct node* gettail(struct linkedlist*);
struct node* getcurrent(struct linkedlist*);
void setcurrent(struct linkedlist*, struct node*);

struct linkedlist* newlist();

void insertfrontmost(struct linkedlist*, struct data*);
void insertbackmost(struct linkedlist*, struct data*);
void insertback(struct linkedlist*, struct data*);

void outputlist(struct linkedlist*);

// other function declarations.

#endif

