#include<iostream>
#include"../include/head.h"
using namespace std;

int main()
{
	char c[20];
	int z;
	cout<<"\n Enter expression :";
	cin.getline(c,20);
	z = postfix(c);
	cout<<"\nexpression evaluates to =  "<<z<<endl;
	return 0;
}
