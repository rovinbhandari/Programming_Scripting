#include <operations.h>
#include <assert.h>
#include <stdio.h>

LinkedList* intnumbertolinkedlist(int x)
{
	LinkedList* ll = newlist();
	do
		insertbackmost(ll, inttodata(x % 10));
	while(x /= 10);
	return ll;
}

inline static int raisedto10(int p)
{
	int x = 1;
	while(p--)
		x *= 10;
	return x;
}

int linkedlisttointnumber(LinkedList* ll)
{
	assert(ll->phead);
	int x = 0, power = 0;
	Node* n = ll->phead;
	do
		x += datatoint(n->pdata) * raisedto10(power++);
	while(n = n->pnext);
	return x;
}

LinkedList* stringnumbertolinkedlist(char* s)
{
	LinkedList* ll = newlist();
	for(; *s; s++)
		insertfrontmost(ll, inttodata(*s - '0'));
	return ll;
}

#define MAXDIGITS	1024
static char stringnumber[MAXDIGITS];

char* linkedlisttostringnumber(LinkedList* ll)
{
	assert(ll->phead);
	Node* n = ll->phead;
	int i = 0;
	do
		*(stringnumber + i++) = datatoint(n->pdata);
	while((n = n->pnext) && i < MAXDIGITS);
	assert(i < MAXDIGITS);
	*(stringnumber + i) = '\0';
	return stringnumber;
}

LinkedList* add(LinkedList* ll1, LinkedList* ll2)
{
	assert(ll1->phead);
	assert(ll2->phead);
	LinkedList* llsum = newlist();
	Node* n1 = ll1->phead;
	Node* n2 = ll2->phead;
	int carry = 0, sum;
	while(n1 || n2)
	{
		sum = (n1 ? datatoint(n1->pdata) : 0)
			+ (n2 ? datatoint(n2->pdata) : 0)
			+ carry;
		carry = sum / 10;
		insertbackmost(llsum, inttodata(sum % 10));
		n1 = n1 ? n1->pnext : NULL;
		n2 = n2 ? n2->pnext : NULL;
	}
	return llsum;
}

LinkedList* subtract(LinkedList* ll1, LinkedList* ll2)
{
	assert(ll1->phead);
	assert(ll2->phead);
	LinkedList* lldiff = newlist();
	Node* n1 = ll1->phead;
	Node* n2 = ll2->phead;
	int borrow = 0, difference;
	while(n1)	// assuming that |ll1| >= |ll2|
	{
		difference = datatoint(n1->pdata)
				   -  borrow
				   - (n2 ? datatoint(n2->pdata) : 0);
		if(difference < 0)
		{
			borrow = 1;
			difference += 10;
		}
		else
			borrow = 0;
		insertbackmost(lldiff, inttodata(difference));
		n1 = n1->pnext;
		n2 = n2 ? n2->pnext : NULL;
	}
	return lldiff;
}

LinkedList* multiply(LinkedList* ll1, LinkedList* ll2)
{
	assert(ll1->phead);
	assert(ll2->phead);
	LinkedList* llsum = newlist();
	Node* n1 = ll1->phead;
	Node* n2 = ll2->phead;
	return llsum;
}

