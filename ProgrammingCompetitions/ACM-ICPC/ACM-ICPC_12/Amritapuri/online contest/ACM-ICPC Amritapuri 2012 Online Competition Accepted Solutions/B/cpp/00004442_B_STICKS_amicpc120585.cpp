#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	
	for(int i=0;i<T;i++)
	{
		int N,M;
		cin>>N;
		cin>>M;
		int* lengths = new int[N];
		for(int j=0;j<N;j++)
		{
			cin>>lengths[j];
		}
		long double max_diag = 0;
		long double temp;
		for(int j=0;j<M;j++)
		{
			long double a,b,c;
			cin>>a>>b>>c;
			temp = sqrt((long double)(a*a+b*b+c*c));
			//cout<<temp<<endl;
			if(temp>max_diag)
			{
				max_diag = temp;
			}
			//cout<<max_diag<<endl;
		}
		int count = 0;
		for(int j=0;j<N;j++)
		{
			//len_sqr = (unsigned long long int)(lengths[j]*lengths[j]);
			if(lengths[j]<=max_diag)
			{
				count++;
			}
		}
		cout<<count<<endl;
		
	}
	return 0;
}
