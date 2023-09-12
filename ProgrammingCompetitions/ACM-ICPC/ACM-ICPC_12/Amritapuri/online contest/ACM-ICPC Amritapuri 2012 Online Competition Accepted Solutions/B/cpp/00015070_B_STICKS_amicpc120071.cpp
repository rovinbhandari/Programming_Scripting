#include<stdio.h>
#include<math.h>
int main()
{
	int x,z;
	scanf("%d",&z);
	for(x=0;x<z;x++)
	{
		long long int n,m;
		scanf("%lld%lld",&n,&m);
		long long int i,ans=0;
		long double a[n],l,b,h;
		long double max=0,now=0;
		long double g;
		for(i=0;i<n;i++)
		{
			scanf("%Lf",&a[i]);
		}
		for(i=0;i<m;i++)
		{
			scanf("%Lf%Lf%Lf",&l,&b,&h);
			g=l*l+b*b+h*h;
			now=sqrt(g*1.0);
			if(now>max)
			{
				max=now;
			}
		}
		for(i=0;i<n;i++)
		{
			if(a[i]>max)
			{
				g=1;
			}
			else
			{
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
