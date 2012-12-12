#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t,n,m,count=0;
	cin>>t;
	while(t--)
	{
	count=0;
	cin>>n>>m;
	long long abc,L[n],A,B,C,square=0;
	for(int i=0;i<n;i++)
		cin>>L[i];
	for(int j=0;j<m;j++)
	{
		cin>>A>>B>>C;
		abc=sqrt((A*A)+(B*B)+(C*C));
		if(square<abc)
			square=abc;
	}
	for(int i=0;i<n;i++)
	{
		if(L[i]<=square)
		count++;	
	}
	
	cout<<count<<endl;	
	}

}