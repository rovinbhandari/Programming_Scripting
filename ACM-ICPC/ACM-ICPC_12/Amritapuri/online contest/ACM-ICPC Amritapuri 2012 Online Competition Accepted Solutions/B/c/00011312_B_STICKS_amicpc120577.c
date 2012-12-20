#include<stdio.h>
long long st[50001];
int main()
{
	int t,no_st,no_bx,i,count=0;
	long long ai,bi,ci,maxdi;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&no_st,&no_bx);
		for(i=0;i<no_st;i++)
			scanf("%lld",&st[i]);
		maxdi=0.0;
		for(i=0;i<no_bx;i++)
			{
				scanf("%lld%lld%lld",&ai,&bi,&ci);
				if(((ai*ai)+(bi*bi)+(ci*ci))>maxdi)
					maxdi=((ai*ai)+(bi*bi)+(ci*ci));
			}
		count=0;
		for(i=0;i<no_st;i++)
		{
			if((st[i]*st[i])<=maxdi)
				count++;
		}
		printf("%d\n",count);
	}
	return(0);
}