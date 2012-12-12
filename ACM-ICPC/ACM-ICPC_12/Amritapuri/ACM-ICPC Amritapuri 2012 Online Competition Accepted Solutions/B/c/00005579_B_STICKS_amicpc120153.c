#include<stdio.h>
#include<math.h>
typedef long long int ll;
ll d[50000],a[50000];
int main()
{
	ll t,n,m,l,b,h;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		ll i=0,count=0,nc=n;
		ll maxs=0,maxd=0;
		while(n--)
		{
			scanf("%lld",&a[i++]);
			if(maxs<a[i-1])
				maxs=a[i-1];
		}
		i=0;
		while(m--)
		{
			scanf("%lld%lld%lld",&l,&b,&h);
			d[i++]=l*l+b*b+h*h;
			if(d[i-1]>maxd)
				maxd=d[i-1];
		}
		getchar();
		if(maxs*maxs<=maxd)
		{
			printf("%lld\n",nc);
			continue;
		}
		for(i=0;i<nc;i++)
		{
			if(a[i]*a[i]<=maxd)
				count++;
		}
		printf("%lld\n",count);
	}
	return 0;
}
