#include<iostream>

#include<cstdio>

#include<cmath>

using namespace std;

int main()
{
	long long int t;
	long long int n;
	long long int i;
	long long int l,m,j,count;
	scanf ("%lld",&t);

	long long int a[3];
	while(t--)
	{
		scanf ("%lld%lld",&l,&m);
		long long int  v1[l];
	
	
		
		 count = 0;
		
		long long int p,q,u;
		for ( i = 0; i < l; i++ )
		{
			scanf ("%lld",&v1[i]);
		}
		q=0;

		for ( int j = 0; j < m; j++ )
		{
			for ( i = 0; i < 3; i++ )
			{
				scanf ( "%lld",&a[i]);
			}
			p = (a[2]*a[2] + a[1]*a[1]+ a[0]*a[0]);
			q=q>p?q:p;
		
		
		}

		for (i=0;i<l;i++){
			if (((v1[i]*v1[i]) <= q)){
				count++;
			}
		}
		printf ("%lld\n",count);
	}
	return 0;
}
