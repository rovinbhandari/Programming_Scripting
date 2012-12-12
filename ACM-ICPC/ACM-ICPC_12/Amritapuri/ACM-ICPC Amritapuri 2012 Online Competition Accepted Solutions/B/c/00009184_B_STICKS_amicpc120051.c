#include<stdio.h>
#include<math.h>
int main()
{
long int T,h,b,l,li[50001],m,n;
long int i;
long int max,e;
long count;
scanf("%ld",&T);
for(;T>0;T--)
	{
	scanf("%ld %ld",&n,&m);
			for(i=0;i<n;i++)
				{
					scanf("%ld",&li[i]);
				}
			max=0;	
			for(i=0;i<m;i++)
				{
				scanf("%ld %ld %ld",&h,&b,&l);
				e=(pow(h,2)+pow(b,2)+pow(l,2));
				if(max<=e)
				max=e;
				}
			count=0;
			for(i=0;i<n;i++)
				{
				if(pow(li[i],2)<=max)
				count++;
				}
			printf("%ld\n",count);
	}
return 0;
}
