#include<cstdio>
#include<algorithm>
using namespace std;
#define si(n)                        scanf("%d",&n)


int main()
{
	int t, n, k, l, h, a[1111], *low, *hi, ans;
	si(t);
	while(t--)
	{
		ans=0;
		si(n);
		si(l);
		si(h);
		for(int i=0;i<n;i++)
		{
			si(a[i]);
		}
		sort(a, a+n);
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				low=lower_bound(a+j+1, a+n, (l-a[i]-a[j]));
				hi=upper_bound(a+j+1, a+n, (h-a[i]-a[j]));
				ans+=int(hi-low);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
