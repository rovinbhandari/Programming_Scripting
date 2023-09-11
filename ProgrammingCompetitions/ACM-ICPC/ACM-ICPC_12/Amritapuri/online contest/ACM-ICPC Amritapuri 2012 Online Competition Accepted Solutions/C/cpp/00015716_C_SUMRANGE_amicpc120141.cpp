/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

   * File Name : 3.cpp

   * Purpose :

   * Creation Date : 04-11-2012

   * Last Modified : Sunday 04 November 2012 01:19:50 PM IST

   * Created By :  Shoaib Khan

   _._._._._._._._._._._._._._._._._._._._._.*/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>

//Data Structures
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
using namespace std;

#define FOR(i,a,b)  for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n)    FOR(i,0,n)
#define INF     INT_MAX
#define ALL(x)      x.begin(),x.end()
#define LET(x,a)    __typeof(a) x(a)
#define IFOR(i,a,b)     for(LET(i,a);i!=(b);++i)
#define EACH(it,v)  IFOR(it,v.begin(),v.end())
#define pb      push_back
#define sz(x)       int(x.size())
#define mp      make_pair
#define fill(x,v)   memset(x,v,sizeof(x))
#define si(n)       scanf("%d",&n)
#define pi(n)       printf("%d ",n)
#define pil(n)      printf("%d\n",n)
#define sl(n)       scanf("%lld",&n)
#define sd(n)       scanf("%lf",&n)
#define ss(n)       scanf("%s",n)

typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
typedef queue<int> QU;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n,l,h;
		cin >> n >>l >> h;
		int a[n+10];
		for(int i=0;i<n;i++)
			cin  >> a[i];
		sort(a,a+n);
		int ans=0;
		for(int i=0;i<n-2;i++){
			if(a[i]>((h*1.0)/3.0)){
				break;
			}
			for(int j=i+1;j<n-1;j++){
				if(a[i]+a[j]>((2*h*1.0)/(3*1.0)))break;
				for(int k=j+1;k<n;k++){
					if(a[i]+a[j]+a[k]>h)break;
					if(a[i]+a[j]+a[k]>=l && a[i]+a[j]+a[k]<=h)
						ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
