#include<stdio.h>
#include<stdlib.h>
long long int l[50002],a[50002],b[50002],c[50002],l2,a2,b2,c2,n,m,highestmid=-1;
int int_cmp(const void *a, const void *b) 
{ 
    const long long int *ia = (const long long int *)a; // casting pointer types 
    const long long int *ib = (const long long int *)b;
    return *ia  - *ib; 
	/* integer comparison: returns negative if b > a 
	and positive if a > b */ 
} 
void bsearch2(int low,int high)
{
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(mid<highestmid)
			return;
		if(fit(mid)==1)
		{
			highestmid=mid;
			bsearch2(mid+1,high);
		}
		else
		{
			bsearch2(low,mid-1);
		}
	}
		return;
}
int fit(int i)
{
long long int j;
for(j=0;j<m;j++)
{
	l2=l[i]*l[i];
	a2=a[j]*a[j];
	b2=b[j]*b[j];
	c2=c[j]*c[j];
	if((l[i]<=a[j])||(l[i]<=b[j])||(l[i]<=c[j])||(l2<=a2+b2)||(l2<=b2+c2)||(l2<=c2+a2)||(l2<=a2+b2+c2))
	{
		return 1;
	}
}
return 0;
}

int main()
{
	long long int i,j;
	int flag,t,x;
	scanf("%d",&t);
	for(x=1;x<=t;x++)
	{
		flag=0;
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
			scanf("%lld",&l[i]);
		for(i=0;i<m;i++)
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		qsort(l,n, sizeof(long long int), int_cmp);
		/*for(i=0;i<n;i++)
			printf("%d\t",l[i]);*/
		bsearch2(0,n-1);
		printf("%lld\n",highestmid+1);
		highestmid=-1;
	}
	return 0;
}
