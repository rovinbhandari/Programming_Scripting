#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	long long int t,n,i,j,k,l,x,y,b,c,d,ctr,z,bot,top,mid;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&c,&d);
		long long int a[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);

		ctr=0;
		for(i=0;i<n-2;i++)
		{
			x=a[i];
			k=i+1;
			l=n-1;
			while(k<l)
			{
				y=x+a[k]+a[l];
				if(y>=c && y<=d)
				{
					z=c-(x+a[k]);
					bot=k;
					top=l-1;
					mid=0;
					while(bot<=top && bot>=k && top<l)
					{
						mid=(bot+top)/2;
						if(a[mid]>=z)
							top=mid-1;
						else
							bot=mid+1;
					}
					if(top<k)
						top=k;
					ctr+=l-top;
				}
				if(y>d)
					l--;
				else
					k++;
			}
		}
		printf("%lld\n",ctr);
	}
	return 0;
}
