#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long int i64;
int main()
{
	i64 t,i,j,n[1020],s,h,l,low,up,count;
	for(scanf("%lld",&t);t--;)
	{
		count=0;
		scanf("%lld%lld%lld",&s,&l,&h);
		for(int i=0;i<s;i++) scanf("%lld",&n[i]);
			
			sort(n,n+s);
			for(i=0;i<s-2;i++)
			{
				for(j=i+1;j<s-1;j++)
				{
					low =lower_bound(n+j+1,n+s,l-n[i]-n[j])-n;
					up=upper_bound(n+j+1,n+s,h-n[i]-n[j])-n-1;
					//cout<<low<<" "<<up<<endl;
					count=count+up-low+1;
				}
			}
	printf("%lld\n",count);
	}
}