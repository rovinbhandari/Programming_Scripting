#include "../include/61head.h"
#include "../include/dm.h"

#include <math.h>
#include <iostream>

using namespace std;


template class Difference<int>;
template class Difference<string>;

template class Difference<char>;


int main()
{
	xyz *p,*u;
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
	//cout<<"Area of figure (Length of line) = "<<s[q - 2]->area(p.input(q))<<endl<<endl;
	
	p=p->input(q);
	u=u->input(q);
	
	DistanceManager obj(s[q - 2]->area(p),s[q - 2]->area(u));
	cout<<"Area difference is "<<obj.distance()<<endl;
	
	
	return 0;
}
