#include<stdio.h>
int main()
{
	long long int t,x,y,z,n,m,ans,i;
	long long int d,dm;
	long long int a[100000];
	scanf("%lld",&t);
	while(t--)
	{
		dm=0;ans=0;
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			d=x*x+y*y+z*z;
			if(dm<d)
				dm=d;
		}
		for(i=0;i<n;i++)
			if(dm>=(a[i]*a[i]))ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
