#include "head.h"
#include <iostream>
using namespace std;

node :: node()
{
	i = -1;
	c = 0.0;
	n = NULL;
}

node * node :: ret_list(int degree, bool input = 0)
{
	node *head, *ptr, *temp;			
	int j;
	for(j = 1; degree >= 0; j++, degree--)
	{
		temp = new node;
		if(j == 1)
		{
			head = temp;
			ptr = temp;
		}
		if(input)
		{
			cout<<"Enter the cofficient of x^"<<degree<<" : ";
			cin>>(temp->c);
		}
		temp->i = degree;
		ptr->n = temp;
		ptr = temp;
	}
	return (head);
}
		
void node :: output()
{
	node * ptr = this;
	while(ptr != NULL)
	{
		if(ptr->c != 0)
		{
			cout<<"("<<ptr->c<<")x^"<<ptr->i<<" ";
		}
		ptr = ptr->n;
	}
}

int node :: degree_of()
{
	int size = 0;
	node * ptr = this;
	while(ptr != NULL)
	{
		size++;
		ptr = ptr->n;
	}
	return (size - 1);
}

node * node :: operator +(node * l2)
{
	node * l1 = this;
	node * result;
	result = result->ret_list(l1->degree_of());
	node * ptr;
	ptr = result;
	while(l1 != NULL)
	{
		(ptr->c) = (l1->c) + (l2->c);
		l1 = l1->n;
		l2 = l2->n;
		ptr = ptr->n;
	}
	return (result);
}

node * multiply();
