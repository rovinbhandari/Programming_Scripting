#include<iostream>
using namespace std;
#define NUM 50001
int main()
{
	long t;
	cin>>t;
	while(t--)
	{
		long n,m,i,j,k;
		cin>>n>>m;
		
		long long len[NUM];
		
		for(i=0;i<n;i++)
		cin>>len[i];
		
		long long a,b,c;
		long long sq,max=-1;
		while(m--)
		{
			cin>>a>>b>>c;
			sq=a*a+b*b+c*c;
			if(max<sq) max=sq;
		}
		long count=0;
		for(i=0;i<n;i++)
		{
			long long p=len[i]*len[i];
			if(p<=max) count++;
		}
		
		cout<<count<<endl;
	}
}
		
		
