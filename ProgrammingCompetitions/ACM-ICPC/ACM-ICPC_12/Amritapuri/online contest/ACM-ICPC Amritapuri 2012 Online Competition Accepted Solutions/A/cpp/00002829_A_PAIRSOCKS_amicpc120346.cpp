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

int main(int argc,char **argv)
{
  //  fii;
  int kase=GI;
  while(kase--)
    {
      map<char,int> m;
      m['R']=m['G']=m['B']=m['W']=0;
      string s;
      cin>>s;
      REP(i,s.length()) {
	m[s[i]]++;
      }
      bool ans=true;
      if((m['R']%2)||(m['G']%2)||(m['B']%2)||(m['W']%2)) ans=0;
      if(ans) printf("YES\n");
      else printf("NO\n"); 
    }
}
