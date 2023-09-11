#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;

#define MOD 1000000007ll

int main()
{
	int t;
	cin>>t;
	while( t-- )
	{
		int n, m;
		scanf("%d %d", &n, &m);
		vector <long long> sticks(n);
		for( int i=0;i<	n;i++)
			scanf("%lld", &sticks[i]);
		double best = 0;
		for( int i=0;i<m;i++)
		{
			double a, b, c;
			scanf("%lf %lf %lf", &a, &b, &c);
			double sol = a*a + b*b + c*c;
			if( sol > best )
				best = sol;
		}

		int count = 0;
		for( int i=0;i<n;i++)
			if( sticks[i]*sticks[i] <= best )
				count++;

		printf("%d\n", count);
	}
	return 0;
}
				

			
	

