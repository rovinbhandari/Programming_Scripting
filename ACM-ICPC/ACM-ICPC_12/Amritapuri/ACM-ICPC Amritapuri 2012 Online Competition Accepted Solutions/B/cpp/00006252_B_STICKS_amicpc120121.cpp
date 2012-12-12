#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <queue>
#include <cassert>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define reprev(i,a,n) for(int i=a;i>n;i--)
#define in(n) scanf("%d",&n)
#define inl(n) scanf("%lld",&n)
#define out(n) printf("%d ",n)
#define outln(n) printf("%d\n",n)
#define outl(n) printf("%lld ",n)
#define outlln(n) printf("%lld\n",n)
#define LL long long 
#define pb push_back
using namespace std;
long long int binaryupper(long long int a[],long long int m,int l,int u)
{
	long long int mid,c=0;
	if(l<=u)
	{
		mid=(l+u)/2;
		if(m==a[mid])
		{
			c=m;
			return binaryupper(a,m,mid+1,u);
		}
		else if(m<a[mid])
		{
			return binaryupper(a,m,l,mid-1);
		}
		else
		{
			return binaryupper(a,m,mid+1,u);
		}
	}
	else
		return u;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		long long int l[n];
		long long int max1=0;
		rep(i,0,n)
		{
			scanf("%lld",&l[i]);
			l[i]=l[i]*l[i];
		}
		long long int a[m],b[m],c[m],ans[m];
		rep(i,0,m)
		{
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			ans[i]=a[i]*a[i]+b[i]*b[i]+c[i]*c[i];
			if(ans[i]>max1)
				max1=ans[i];
		}
		int count=0;
		rep(i,0,n)
		{
			if(l[i]<=max1)
				count++;
		}
		printf("%d\n",count);

	}
	
	return 0;
}
