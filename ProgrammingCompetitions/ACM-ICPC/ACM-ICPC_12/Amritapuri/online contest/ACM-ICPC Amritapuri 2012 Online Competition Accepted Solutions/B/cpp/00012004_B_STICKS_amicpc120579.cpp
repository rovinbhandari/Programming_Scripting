#include<stdio.h>
#include<math.h>
int main()
{
    long long int t,n,i,m,a[50005],b[50005],c[50005],l[50005],c1,j;
    long long int d[50005],q;
    scanf("%lld",&t);
    while(t--)
    {
		c1=0;
		scanf("%lld",&n);
		scanf("%lld",&m);
	
		for(i=0;i<n;i++)
		scanf("%lld",&l[i]);
	
		for(i=0;i<m;i++)
		{		
			scanf("%lld",&a[i]);
			scanf("%lld",&b[i]);
			scanf("%lld",&c[i]);
		}
		int max;
		max=d[0];
	    for(i=0;i<m;i++)
	    {
			d[i]=sqrt(a[i]*a[i]+b[i]*b[i]+c[i]*c[i]);
			if(d[i]>=max)
			max=d[i];
			}
		for(i=0;i<n;i++)
		{	
	      if(max>=l[i])
	      c1++;
		}
		printf("%lld\n",c1);
	}
    return 0;
}
