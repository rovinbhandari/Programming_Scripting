
#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <string>
#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p,0,sizeof(p))
#define LL long long int
#define ULL unsigned long long int
#define S(n)					scanf("%d",&n)
#define Sl(n)					scanf("%lld",&n)
#define Sf(n) 					scanf("%lf",&n)
#define Ss(n) 					scanf("%s",n)
using namespace std;
int arr[1010];
int main()
{
	int i,j,k,m,n,t;

	S(t);
	while(t--)
	{
		int h,l;
		S(n);
		S(l),S(h);
		for(i=0;i<n;i++)
		S(arr[i]);
		sort(arr,arr+n);
		LL ans=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n-1;j++)
			{
				int v=arr[i]+arr[j];
				int* lw=lower_bound(arr+j+1,arr+n,l-v);
				int* hg=upper_bound(arr+j+1,arr+n,h-v);
				
				ans+=(hg-lw);
				
			}
		}
		printf("%lld\n",ans);
		
		
		
	}
	return 0;
}
