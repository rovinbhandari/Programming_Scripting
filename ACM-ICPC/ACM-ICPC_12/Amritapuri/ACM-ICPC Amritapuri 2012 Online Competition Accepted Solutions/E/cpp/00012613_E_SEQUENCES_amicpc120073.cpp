
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
int a[300000];
int seg[1<<20];
void init(int p,int curl,int curr)
{
	if(curl==curr)
	{
		seg[p]=a[curl];
	}
	else
	{
		int mid=(curl+curr)/2;
		init(2*p,curl,mid);
		init(2*p+1,mid+1,curr);
		seg[p]=max(seg[2*p],seg[2*p+1]);
	}
}

int query(int p,int curl,int curr,int l,int r)
{
	if(max(curl,l)>min(curr,r))
		return -INF;
	if(curl>=l&&curr<=r)
		return seg[p];
	else
	{
		int ansl,ansr;
		int mid=(curl+curr)/2;
		ansl=query(2*p,curl,mid,l,r);
		ansr=query(2*p+1,mid+1,curr,l,r);
		return max(ansl,ansr);
	}
}

int ones[300000];
string s;
int main(){
	int l,r,t,n,i,q,maxlr,oneslr;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		cin>>s;
		s="1"+s;
		a[0]=ones[0]=0;
		for(i=1;i<=n;i++){
			if(s[i]=='1')
				a[i]=a[i-1]-1;
			else
				a[i]=a[i-1]+1;
			ones[i]=ones[i-1];
			ones[i]+=(s[i]=='1');
		}
		init(1,1,n);
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&l,&r);
			maxlr=query(1,1,n,l,r);
			oneslr=ones[r]-ones[l-1];
			//		printf("%d %d %d\n",maxlr,oneslr,a[l-1]);
			printf("%d\n",max(oneslr,maxlr+oneslr-a[l-1]));
		}
	}
	return 0;
}
