#include "../include/61head.h"
#include <math.h>
#include <iostream>
using namespace std;

xyz :: xyz()
{
	x = y = z = 0.0;
}

xyz * xyz :: input(int q)
{
	xyz * pt = new xyz[q];
	int i = 1;
	cout<<"\nEnter points (in order) :\n";
	while(q--)
	{
		 cout<<"x-ordinate of pt"<<i<<" : ";
		 cin>>pt[i-1].x;
		 cout<<"y-ordinate of pt"<<i<<" : ";
		 cin>>pt[i-1].y;
		 cout<<"z-ordinate of pt"<<i<<" : ";
		 cin>>pt[i-1].z;
		 i++;
	}
	cout<<endl;
	return pt;
}

float line :: area(xyz * pt)
{
	float len = 0.0;
	len = sqrt(pow((pt[0].x - pt[1].x), 2) + pow((pt[0].y - pt[1].y), 2) + pow((pt[0].z - pt[1].z), 2));
	return (len);
}

float triangle :: area(xyz * pt)
{
	float ar = 0.0;
	float * len = new float[3];
	int i = 0;
	xyz * temp = new xyz[2];
	line ln;
	while(i < 3)
	{
		temp[0] = pt[i];
		temp[1] = pt[(i + 1) % 3];
		len[i] = ln.area(temp);
		i++;
	}
	float s = 0.5 * (len[0] + len[1] + len[2]);
	ar = sqrt(s * (s - len[0]) * (s - len[1]) * (s - len[2]));
	return (ar);
}

float rectangle :: area(xyz * pt)
{
	float ar = 0.0;
	float * tri = new float[2];
	int i = 0;
	xyz * temp = new xyz[3];
	triangle ta;
	while(i < 2)
	{
		temp[0] = pt[i];
		temp[1] = pt[i + 1];
		temp[2] = pt[(i + 2) % 4];
		tri[i] = ta.area(temp);
		i++;
	}
	ar = tri[0] + tri[1];
	return (ar);
}
