#include "../include/61head.h"
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	xyz p;
	line l;
	triangle t;
	rectangle r;
	shape* s[3];
	s[0] = &l;
	s[1] = &t;
	s[2] = &r;
	cout<<"\nEnter the number of points to enter : ";
	int q = 0;
	cin>>q;
	if(q > 4 || q < 2)
	{
		cout<<"enter a value from 2 to 4";
		return 0;
	}
	cout<<"Area of figure (Length of line) = "<<s[q - 2]->area(p.input(q))<<endl<<endl;
	return 0;
}
