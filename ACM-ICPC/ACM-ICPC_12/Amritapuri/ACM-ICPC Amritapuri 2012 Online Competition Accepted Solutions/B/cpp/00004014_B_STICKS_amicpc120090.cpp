// LIBRARIES
#include<iostream>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<algorithm>

// DATA STRUCTURES
#include<string>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<map>

// OTHERS
#define L(a) list< a >
#define V(a) vector< a >
#define S(a) stack< a >
#define Q(a) queue< a >
#define P(a,b) pair< a , b >
#define M(a,b) map< a , b >
#define H(a) priority_queue< a >
#define Hm(a) priority_queue< a, vector<a>, greater<a> >
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FOR_D(i,a,b) for(int i=a-1;i>=b;i--)
#define f first
#define s second
#define pb push_back
typedef long long int lli;
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,m,i,d,l,h,b;
		double x,max_d=0;
		scanf("%lld%lld",&n,&m);
		double a[n];
		for(i=0;i<n;i++)
			scanf("%lf",&a[i]);
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&l,&b,&h);
			d=max(l*l+b*b,b*b+h*h);
			d=max(d,h*h+l*l);
			d=max(d,l*l+b*b+h*h);
			x=sqrt((double)d);
			if(x>max_d)
				max_d=x;
		}
		int count=0;
		for(i=0;i<n;i++)
			if(a[i]<=max_d)
				count++;
		printf("%d\n",count);
	}
	return 0;
}
