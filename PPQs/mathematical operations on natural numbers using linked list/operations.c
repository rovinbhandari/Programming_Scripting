#include <operations.h>
#include <assert.h>

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
	while((n = n->pnext) != ll->ptail && n);
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
	while((n = n->pnext) != ll->ptail && n && i < MAXDIGITS);
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
	do
	{
		sum = datatoint(n1->pdata) + datatoint(n2->pdata) + carry;
		carry = sum / 10;
		sum = sum % 10;
		insertbackmost(llsum, inttodata(sum));
		n1 = n1->pnext;
		n2 = n2->pnext;
	}
	while(n1 != ll1->ptail && n2 != ll2->ptail && n1 && n2);
	return llsum;
}

LinkedList* subtract(LinkedList* ll1, LinkedList* ll2)
{
	assert(ll1->phead);
	assert(ll2->phead);
	LinkedList* llsum = newlist();
	Node* n1 = ll1->phead;
	Node* n2 = ll2->phead;

	return llsum;
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

