#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double l[100000];
	double tm,max,a,b,c;
	int cases,cnt,n,m,i;
	cin>>cases;
	while(cases--)
	{
		max=0.0;
		cnt=0;
		cin>>n>>m;
		for(i=0; i<n; i++)
			cin>>l[i];
		for(i=0; i<m; i++)
		{
			cin>>a>>b>>c;
			tm=sqrt(a*a + b*b + c*c);
			if(tm>max)
				max=tm;
		}
		for(i=0; i<n; i++)
		{
			if(l[i]<=max)
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
