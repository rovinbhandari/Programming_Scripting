#include<cstdio>
#include<iostream>
#define MAXLEN 100000
using namespace std;
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int s[MAXLEN];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&s[i]);
		}
		long long l,b,h,d[MAXLEN];
		for(int i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&l,&b,&h);
			d[i]=(l*l)+(b*b)+(h*h);
		}
		int maxindex=0;
		for(int j=1;j<m;j++)
		{
			if(d[j]>d[maxindex])
			{
				maxindex=j;
			}	
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			long long x = s[i];
			if((x*x)<=d[maxindex])
			{
				count++;
			}
		}
		printf("%d\n",count);
	}
}
