#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	long long int t,l[100001],k,a,b,c,total,i,sq,sq1,count,n,m;
	//freopen("input.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		total=i=count=0;
		k=n;
		while(n--)
		{
			cin>>l[i];
			i++;
			
		}
		while(m--)
		{
			cin>>a>>b>>c;
			
			sq=a*a+b*b+c*c;
			sq1=sqrt(sq);
			if(sq1>=total)
			{
				total=sq1;
			}
			
			
		}
		
		for(i=0;i<k;i++)
		{
			if(l[i]<=total)
			{
				count++;
				}
		}
		cout<<count<<endl;
		
	}
	return 0;
}

	