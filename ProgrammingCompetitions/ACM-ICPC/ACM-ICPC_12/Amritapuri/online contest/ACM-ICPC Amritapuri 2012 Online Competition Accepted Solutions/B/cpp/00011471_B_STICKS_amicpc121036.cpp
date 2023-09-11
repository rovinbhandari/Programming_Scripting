#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t,n,m,counter=0;
	cin>>t;
	while(t--)
	{
	counter=0;
	cin>>n>>m;
	long long abc,L[n],A,B,C,sq=0;
	for(int i=0;i<n;i++)
		cin>>L[i];
	for(int j=0;j<m;j++)
	{
		cin>>A>>B>>C;
		abc=sqrt((A*A)+(B*B)+(C*C));
		if(sq<abc)
			sq=abc;
	}
	for(int i=0;i<n;i++)
	{
		if(L[i]<=sq)
		counter++;	
	}
	
	cout<<counter<<endl;	
	}

}