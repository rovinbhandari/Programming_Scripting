#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef long long LL;
#define pb push_back
#define mp make_pair
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define SET(x,a) memset(x,a,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define INF (int)1e9
#define fii freopen("ip.txt","r",stdin)
#define fio freopen("out.txt","w",stdout)
struct box {
  LL l,b,h;
  box(){}
} b[50001];

int main() {
  //fii;
  int t=GI,l[50001];
  while(t--) {
    int n=GI,m=GI;
    REP(i,n) l[i]=GI;
	LL res=0;
    REP(i,m) {
		b[i].l=GL, b[i].b=GL, b[i].h=GL;
		LL x=(LL)sqrt(b[i].l*b[i].l+b[i].b*b[i].b+b[i].h*b[i].h);
		if(x>res) res=x;
    }
    int ans=0;
    REP(i,n) if(res>=(LL)l[i]) ans++;
    cout<<ans<<endl;
  }
  return 0;
}

