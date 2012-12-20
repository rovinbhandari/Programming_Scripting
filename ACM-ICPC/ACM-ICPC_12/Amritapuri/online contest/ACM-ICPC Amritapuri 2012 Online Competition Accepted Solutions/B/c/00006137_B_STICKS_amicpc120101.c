#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int comp(const void *x,const void *y)
{	
	long long int a=*(long long int *)x;
	long long int b=*(long long int *)y;
	if(a > b)
		return 1;
	return 0;
}

int main()
{
	long long int t,m,n,i,x,y,z,v,max;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&m,&n);
		long long int a[m];
		for(i=0;i<m;i++)
		{
			scanf("%lld",&a[i]);
			a[i]*=a[i];
		}
		qsort(a,m,sizeof(long long int),comp);
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			v=x*x + y*y + z*z;
			if(v>max)
				max=v;
		}
		
		for(i=0;i<m;i++)
		{
			if(a[i]>max)
				break;
		}
		printf("%lld\n",i);
	}
	return 0;
}
