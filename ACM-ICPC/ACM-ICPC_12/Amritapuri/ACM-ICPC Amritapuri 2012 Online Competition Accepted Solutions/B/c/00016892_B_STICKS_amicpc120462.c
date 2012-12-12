#include<stdio.h>
int main()
{
	int tc;
	long long int arr[50001];
	long long int x,y,z,max=0,n,m,i,t,count;
	scanf("%d",&tc);
	while(tc--)
	{
		max=0;
		count=0;
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			t=x*x+y*y+z*z;
			if(max<t)
				max=t;
		}

		for(i=0;i<n;i++)
		{
			if(arr[i]*arr[i]<=max)
				count++;
		}
		printf("%lld\n",count);

	}
return 0;
}
