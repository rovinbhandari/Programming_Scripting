
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<climits>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

#define REP(i,s,n)  for (int i=(s),_n=(n);i<=_n;i++)
#define FOR(i,s,n)  for (int i=(s),_n=(n);i<_n;i++)
#define REPD(i,e,s)  for (int i=(e),_s=(s);i>=_s;i--)
#define tr(container, it) \
		        for (typeof(container.begin()) it=container.begin(); it!=container.end();it++)
#define PB push_back

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

int main() {
	int t;
	cin >> t;
	while (t--) {
		LL n,l,h;
		scanf("%lld%lld%lld",&n,&l,&h);
		LL arr[1010];
		FOR(i,0,n) scanf("%lld",&arr[i]);
		sort(arr,arr+n);
		LL cnt=0;
		for (int i=0;i<n;i++) {
			for (int j=i+1;j<n;j++) {
				LL val1=l-arr[i]-arr[j]-1;
				LL val2=h-arr[i]-arr[j];
				LL ind1=(LL)(upper_bound(arr,arr+n,val1)-arr);
				LL ind2=(LL)(upper_bound(arr,arr+n,val2)-arr);
				if (ind1<=j) ind1=j+1;
				if (ind2<=j) ind2=j+1;
				cnt+=(ind2-ind1);
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
