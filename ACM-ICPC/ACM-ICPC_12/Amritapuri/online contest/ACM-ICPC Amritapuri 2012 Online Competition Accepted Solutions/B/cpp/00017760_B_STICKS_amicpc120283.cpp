#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <math.h>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

#define FOR(i, n) for(i=0;i<n;++i)
#define FORD(i, n) for(i=n-1;i>=0;--i)
#define S(T) scanf("%d", &T)
#define SL(T) scanf("%lld", &T)
#define fill(a, val ,count) memset(a, val, count*sizeof(a))
#define SORT(x,n) sort(x,x+n)
#define SORTD(x,n) sort(x,x+n,std::greater<int>())

int main()
{
	int n,t,i,j,k,m;
	double a[50001];
	double d[50001][3];
	double f[50001];
	//freopen("in.txt","r",stdin);
	
	S(t);
	
	while(t--) {
		S(n); S(m);
		
		FOR(i,n) {
			scanf("%lf",&a[i]);
		}
		
		FOR(i,m) {
			scanf("%lf",&d[i][0]);
			scanf("%lf",&d[i][1]);
			scanf("%lf",&d[i][2]);
			f[i]=sqrt(d[i][0]*d[i][0]+d[i][1]*d[i][1]+d[i][2]*d[i][2]);
		}
		
		sort(f,f+m,std::greater<double>());
		sort(a,a+n);
		int count=0;
		j=0;
		i=0;
		if(m==0){
			cout<<count<<"\n";
			continue;
		}	
		FOR(i,n) {
			if(a[i]<=f[0]) count++;
		}
		
		cout<<count<<"\n";
		
	}
	
	return 0;
}
