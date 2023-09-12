#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 1000000
int sum[MAX+100];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,L,H;
		scanf("%d%d%d",&n,&L,&H);
		int a[n];
		int i,j,k;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int count = 0;
		for(i=0;i<n;i++) 
		{
			if(a[i]>H)
				break;
			for(j=i+1;j<n;j++)
			{
				if (a[i] + a[j] > H) 
					break;
				for(k=j+1;k<n;k++) 
				{
					int sum = a[i] + a[j] + a[k];
					if(sum>H)
						break;
					if (L <= sum && sum <= H)
						count++;;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
