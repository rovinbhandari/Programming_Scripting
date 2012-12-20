
/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)	
#define mod 1000000007
#define MAXN 1000010
#define MP make_pair
#define INF mod

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;

int x[4000000],a[1000005];
int main(){
	int n,t,ks,ke,i,l,h,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&l,&h);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		a[n+1]=INF;
		int ans=0;
		for(i=1;i<=n;i++){
			ks=ke=n+1;
			for(j=i+1;j<=n;j++){
				ks=max(ks,j);
				while(a[ks]+a[i]+a[j]>=l && ks>j)
					ks--;
				ke=max(ks,ke);
				while(a[ke]+a[i]+a[j]>h && ke>ks)
					ke--;
				ans+=(ke-ks);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
