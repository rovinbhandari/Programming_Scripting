#include "head.h"
#include <iostream>
using namespace std;

int main()
{
	node * l1;
	cout<<"\n";
	int degree = 5;
	l1 = l1->ret_list(degree, 1);
	l1->output();
	cout<<"\n"<<l1->degree_of()<<"\n";
	node * l2;
	cout<<"\n";
	l2 = l2->ret_list(degree, 1);
	l2->output();
	cout<<"\n"<<l2->degree_of()<<"\n";
	node * result = l1->add(l2);
	cout<<"ON ADDITION : \n";
	result->output();
	cout<<"\n"<<result->degree_of()<<"\n";
}
