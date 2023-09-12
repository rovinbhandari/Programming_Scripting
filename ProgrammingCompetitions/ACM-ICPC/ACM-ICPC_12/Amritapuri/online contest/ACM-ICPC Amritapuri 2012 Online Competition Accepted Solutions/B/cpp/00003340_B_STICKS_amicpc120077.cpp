// Author : Segment3

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<vector>
#include<map>
#define LLD long long int
#define MAX 1000000007
using namespace std;
long long int L[1000002];
int main()
{
	int i,j,n,m,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%lld",&L[i]);
		long long int l,b,h;
		long long int maxdiag=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&l,&b,&h);
			maxdiag = max(maxdiag,l*l+h*h+b*b);
		}

		int c = 0;
		for(i=0;i<n;i++)
		{
			if(L[i]*L[i] <= maxdiag)
				c++;
		}

		printf("%d\n",c);



	}


	return 0;

}
