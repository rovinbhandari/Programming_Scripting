
// This works!!
//Data-structures includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<list>

//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<limits.h>

using namespace std;

#define s(n)		scanf("%d",&n)
#define sf(n) 		scanf("%lf",&n)
#define ss(n) 		scanf("%s",n)
#define pb		push_back
#define mp	 	make_pair
#define fill(a,v) 	memset(a, v, sizeof(a))
#define SZ(v)		(int)(v.size())
#define all(x)		x.begin(), x.end()
#define INDEX(arr,ind)	(lower_bound(all(arr),ind)-arr.begin())
#define FF		first
#define SS		second
#define EPS		1e-9
#define INF		(int)1e9
#define LINF		(long long)1e18
#define FOR(i,a,b)	for(int i=a;i<b;i++)
#define REP(i,n)	FOR(i,0,n)
#define T(t)            int t;scanf ("%d",&t);while (t--)

typedef vector<int> VI;
typedef priority_queue<int> MXHEAP;
typedef priority_queue<int,VI,greater<int> > MNHEAP;
typedef vector<vector<int> > VVI;
typedef long long int LL;
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
typedef pair<double,double> PDD;

int main()
{
	T(t){
	int n,ans=0,L,H,i,x,Tr,tmp,j;
	s(n),s(L),s(H);
	VI v1;
	ans=0;
	for(i=0;i<n;i++)
	{
		s(x);
		v1.pb(x);
	}
	if(n<3)
	{
		puts("0");
		continue;
	}
	if(v1[0]>v1[1])
		swap(v1[0],v1[1]);
	for(i=2;i<n;i++)
	{
		int l=0;
		int r=i-1;
		Tr=H-v1[i];
		int ct=0;
		while(l<r)
		{
			if(v1[l]+v1[r]>Tr)
				r--;
			else
			{
				ct+=r-l;
				l++;
			}
		}
		int ct1=0;
		l=0;
		r=i-1;
		Tr=L-v1[i]-1;
		while(l<r)
		{
			if(v1[l]+v1[r]>Tr)
				r--;
			else
			{
				ct1+=r-l;
				l++;
			}
		}
		ans+=ct-ct1;
		tmp=v1[i];
		for(j=i-1;v1[j]>=tmp;j--)
			v1[j+1]=v1[j];
		v1[j+1]=tmp;
	}
	cout << ans << endl;
	}
	return 0;
}
