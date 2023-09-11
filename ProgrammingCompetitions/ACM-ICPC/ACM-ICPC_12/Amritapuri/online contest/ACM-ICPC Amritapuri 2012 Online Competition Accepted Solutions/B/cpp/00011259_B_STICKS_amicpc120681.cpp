//============================================================================
// Name        : hello.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

int N,M;
double size[500000];
double sticks[500000];

double max1(int n){
	double max = size[0];
	for(int i=0;i<n;i++){
		if(size[i] > max)
			max = size[i];
	}
	return max;

}

int instances(double d,int n){
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(size[i] == d)
			count++;
	}
	return count;
}

int main() {

	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d %d",&N,&M);

		for(int j=0;j<N;j++)
		{
			scanf("%lf",&sticks[j]);
		}


		for(int j=0;j<M;j++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			double d = sqrt((double)a*a + b*b +c*c);
			size[j] = d;
		}
		char c;
//		scanf("%c",&c);
//		scanf("%c",&c);

		double max_size = max1(M);
		int inst = instances(max_size,M);
		int count = 0;

		for(int j=0;j<N;j++)
		{
			if( sticks[j] <= max_size )
			{
				count++;
				continue;
			}
			if( sticks[j] == max_size && inst > 0 )
			{
				inst--;
	//			count++;
			}
		}
		printf("%d\n",count);


	}

	return 0;
}
