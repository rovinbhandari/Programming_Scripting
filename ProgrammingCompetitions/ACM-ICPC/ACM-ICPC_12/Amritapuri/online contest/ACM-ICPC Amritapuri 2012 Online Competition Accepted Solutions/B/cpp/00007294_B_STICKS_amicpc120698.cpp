#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n, m;
		long l, b, h, maxLength, dTmp, count;
		vector <long> sticks;
		sticks.clear();
		maxLength = 0;
		count = 0;
		scanf("%d %d",&n,&m);
		while(n--)
		{
			scanf("%ld",&dTmp);
//			dTmp *= dTmp;	//extra ste//p
			sticks.push_back(dTmp);
		}
		while(m--)
		{
			scanf("%ld %ld %ld",&l,&b,&h);
			dTmp = sqrt(l*l + b*b + h*h);
			if (dTmp > maxLength)
				maxLength = dTmp;
		}
		n = sticks.size();
		while(n--)
		{
			if (sticks[n] <= maxLength)
				count++;
		}
		printf("%ld\n",count);
	}
	return 0;
} 
