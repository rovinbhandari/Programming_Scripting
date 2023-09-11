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
int main() {
  //fii;
  int t=GI;
  while(t--) {
    string s;
    cin>>s;
    int x[1000];
    SET(x,0);
    REP(i,s.length()) x[s[i]]++;
    int ok=1;
    REP(i,s.length()) if(x[s[i]]%2) ok=0;
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}

