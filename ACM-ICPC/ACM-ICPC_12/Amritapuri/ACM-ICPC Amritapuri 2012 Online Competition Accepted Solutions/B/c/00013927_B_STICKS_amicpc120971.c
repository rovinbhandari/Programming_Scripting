#include<stdio.h>
int main()
{
	int test,a;
	long int i,p,q,r,n,m,count,op[12];
	long int l[50000],diag,max=0;
	scanf("%d",&test);
	for(a=0;a<test;a++)
	{
		count=0;
		scanf("%ld%ld",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%ld",&l[i]);
			l[i]*=l[i];
//			printf("%ld",l[i]);
//			printf("%lld\n",l[i]);
		}
		max=0;
		for(i=0;i<m;i++)
		{
			scanf("%ld%ld%ld",&p,&q,&r);
			diag=(p*p)+(q*q)+(r*r);
			if(diag>=max)
				max=diag;
		}
		for(i=0;i<n;i++)
		{
			if(l[i]<=max)
				count++;
		}
		op[a]=count;
	}
	for(a=0;a<test;a++)
		printf("%ld\n",op[a]);
	return 0;
}
