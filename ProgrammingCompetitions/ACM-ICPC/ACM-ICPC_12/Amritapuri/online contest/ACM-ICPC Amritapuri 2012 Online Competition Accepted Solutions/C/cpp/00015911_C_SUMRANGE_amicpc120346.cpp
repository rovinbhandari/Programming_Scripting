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
#define GD ({double t;scanf("%lf",&t);t;})
#define GC ({char t;scanf("%c",&t);t;})
#define SET(x,a) memset(x,a,sizeof(x))
#define ALL(x) (x.begin(),x.end())
#define INF (int)1e9
#define fii freopen("in.txt","r",stdin)
#define fio freopen("out.txt","w",stdout)
#define MOD 1000000007
template<class T> inline T big(T a,T b) {return a>b?a:b;} 
template<class T> inline T small(T a,T b) {return a<b?a:b;} 


int n,l,h;
vector<int> a(1001);
LL arr[1000001];
LL temp[1000001];
int main(int argc,char **argv)
{
  int kase=GI;
  while(kase--) {
    REP(i,1001) a[i]=INF;
    n=GI,l=GI,h=GI;
    REP(i,n) a[i]=GI;
    sort(a.begin(),a.end());
    int si=n,ei=0;
    REP(i,n) {
      if(a[i]<h) break;
      ei++;
    }
    int cnt=-1;
    REP(i,n) FOR(j,i+1,n-1) {
      cnt++;
      temp[cnt]=a[i]+(LL)a[j];
      arr[cnt]=j;
      if(temp[cnt]>h) j=n;
    }

    cnt++;
    //    sort(temp,temp+cnt);
    vector<int>::iterator low,up;
    int ans=0;
    FOR(i,0,cnt) {
      low = upper_bound(a.begin()+(arr[i]+1),a.begin()+n,h-temp[i]);
      up = lower_bound(a.begin()+(arr[i]+1),a.begin()+n,l-temp[i]);
      //   cout<<abs(l-temp[i])<<" ";
      int temp1=((int)(low-up));
      //      cout<<temp[i]<<" "<<((int)(low-a.begin()))<<" "<<((int)(up-a.begin()))<<"\n";
      if(temp>0) ans+=temp1;
    }
    cout<<ans<<"\n";
  }
}
