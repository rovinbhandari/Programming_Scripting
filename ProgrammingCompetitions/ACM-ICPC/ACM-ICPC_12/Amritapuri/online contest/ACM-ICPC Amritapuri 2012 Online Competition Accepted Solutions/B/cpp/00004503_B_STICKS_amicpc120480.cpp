#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,m,l,b,h;
		long long int ln[50001];
		long long int mx[50001];
		scanf("%lld%lld",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&ln[i]);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&l,&b,&h);
			mx[i] = sqrt(l*l + b*b + h*h);
		}
		sort(mx,mx+m);
		long long int count=0;
		for(int i=0;i<n;i++)
		{
			if(ln[i]<=mx[m-1])count++;
		}
		printf("%lld\n",count);
	}
	return 0;
}
