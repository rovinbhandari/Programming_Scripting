#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long int i64;
int main()
{
	i64 t,i,n,m;
	i64 l[60000],a,b,c,max,count;
	//i64 max;//b[60000];
	for(scanf("%lld",&t);t--;)
	{
		max=-1;count=0;
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)  scanf("%lld",&l[i]);
		for(i=0;i<m;i++) 
		
		{scanf("%lld %lld %lld",&a,&b,&c);
		i64 d=(i64)sqrt(a*a+b*b+c*c);
		if(max<d) max=d;
		}
		//cout<<max<<endl;
		for(i=0;i<n;i++)  if(max>=l[i]) count++;
		printf("%lld\n",count);
	}
}