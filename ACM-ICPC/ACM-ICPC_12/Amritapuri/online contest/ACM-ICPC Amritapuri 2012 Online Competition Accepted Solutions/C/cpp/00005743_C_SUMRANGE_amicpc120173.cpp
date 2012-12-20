#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int i,t,n,l,h,a[1001],j,k,li,hi,sum=0;

	scanf("%d",&t);

	while(t--)
	{
		scanf("%d %d %d",&n,&l,&h);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);

		sort(a,a+n);

		sum=0;
		for(i=0;i<n-2;i++)
		{
			li=n-1;hi=n-1;
			for(j=i+1;j<n-1;j++)
				{
				while(li>j && a[li]>=l-a[i]-a[j] )
					{
					li--;
					}
				while(hi>j && a[hi]>h-a[i]-a[j] )
					{
					hi--;
					}
				if(j>li) li=j;
				if(j>=hi) break;
				sum+=hi-li;
				}
		}
		printf("%d\n",sum);
	}

	return 0;
}
