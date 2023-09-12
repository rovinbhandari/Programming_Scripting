#include<stdio.h>
#include<math.h>
int main()
{
	long int t,m,n,l[50001],a,b,c,i,s,k,r;
	scanf("%ld",&t);
	while(t--)
	{
		s=0;
		r=0;
		scanf("%ld%ld",&n,&m);
		for(i=0;i<n;i++)
			scanf("%ld",&l[i]);
		for(i=0;i<m;i++)
		{
			scanf("%ld%ld%ld",&a,&b,&c);
			k=a*a+b*b+c*c;
		//	k=sqrt(k);
			if(k>s) s=k;
		}
		for(i=0;i<n;i++)
		{
		//	printf("%ld %ld\n",s,l[i]*l[i]);
			if(l[i]*l[i]<=s)	
				r++;
		}
		printf("%ld\n",r);
	}
	return 0;
}
