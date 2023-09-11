#include<stdio.h>
int main()
{
	int t,n,m,N[50005],count,i;
	long long int max,m1,l,b,h;
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%d",&N[i]);
		}
		max=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld %lld %lld",&l,&b,&h);
			m1=((l*l)+(h*h)+(b*b));
			if(m1>max)
				max=m1;
		}
		count=0;
		for(i=0;i<n;i++)
		{
			m1=(long long int)N[i];
			if((m1*m1)<=max)
				count++;
		}
		printf("%d\n",count);
		t--;
	}
	return 0;
}
