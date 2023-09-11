#include<stdio.h>
int main()
{
	int t,n,m,i,count,j;
	long long int d,max,a,b,c;
	long long int l[50000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&l[i]);
		}
		max=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			d=a*a + b*b + c*c;
			if(d>max)
			max=d;
		}
		count=0;
		for(i=0;i<n;i++)
		{
				d=l[i]*l[i];
				if(d<=max)	
					count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
