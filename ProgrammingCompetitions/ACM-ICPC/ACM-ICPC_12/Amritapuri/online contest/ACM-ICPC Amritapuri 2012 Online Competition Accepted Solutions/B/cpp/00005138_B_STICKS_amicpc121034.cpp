#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	unsigned long long  b,h,ll,md,i,d,tmp,ctr;
	int t , n , m;
	cin>>t;
	while ( t != 0 )
	{
		t--;
		md = 0;
		cin >> n >> m;
		vector <int> l;
		for ( i = 0 ; i < n ; i++ )
		{
			cin>>tmp;
			l.push_back(tmp);
		}
		for ( i = 0 ; i < m ; i++ )
		{
			cin>>ll>>b>>h;
			
			d = sqrt((ll*ll) + (b*b) + (h*h));
			if ( d > md )
			{
				md = d;
			}
		}
		ctr = 0;
		for ( i = 0 ; i < n ; i++ )
		{
			if ( l[i] <= md )
			{
				ctr++;
			}
		}
		cout << ctr <<endl;
	}
	return 0;
}

