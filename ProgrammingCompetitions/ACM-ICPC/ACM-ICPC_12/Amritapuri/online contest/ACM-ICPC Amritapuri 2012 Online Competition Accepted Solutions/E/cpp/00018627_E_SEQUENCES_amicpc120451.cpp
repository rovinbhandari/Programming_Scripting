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
#define MAXN 100000
int n,q,a[MAXN];
string s;
struct node
{
  int szez,sze1,s1e1;
  node(){}
  node(int a,int b,int c)
  {
    szez=a,sze1=b,s1e1=c;
  }
} tree[3*MAXN+1];
node calc(node a,node b)
{
  if(a.szez==-INF) return b;
  else if(b.szez==-INF) return a;
  node ans;
  ans=node(a.szez+b.szez,max(a.szez+b.sze1,max(a.szez+b.s1e1,a.sze1+b.s1e1)),a.s1e1+b.s1e1);
  return ans;
}
void build(int i,int l,int h)
{
  if(l==h){ tree[i]=node(s[l]=='0',s[l]=='1',s[l]=='1');return;}
  int mid=(l+h)>>1;
  build(2*i+1,l,mid);
  build(2*i+2,mid+1,h);
  tree[i]=calc(tree[2*i+1],tree[2*i+2]);
}
node query(int i,int l,int h,int s,int e)
{
  if(l>=s && h<=e) return tree[i];
  if(h<s || l>e) return node(-INF,-INF,-INF);
  int mid=(l+h)>>1;
  node a=query(2*i+1,l,mid,s,e);
  node b=query(2*i+2,mid+1,h,s,e);
  node ans=calc(a,b);
  //cout<<i<<" "<<l<<" "<<h<<" "<<s<<" "<<e<<" "<<ans.l0<<" "<<" "<<ans.l1<<" "<<ans.z<<endl;
  return ans;
}
int main()
{
  //fii;
  int t=GI;
  while(t--) {
    n=GI;
    cin>>s;
    build(0,0,n-1);
    q=GI;
    //REP(i,27) cout<<tree[i].maxval<<" "<<tree[i].maxf<<" "<<tree[i].lval<<" "<<tree[i].lf<<" "<<tree[i].rval<<" "<<tree[i].rf<<endl;
    REP(i,q) {
      int a,b;
      a=GI-1,b=GI-1;
      node ans=query(0,0,n-1,a,b);
      printf("%d\n",max(ans.szez,max(ans.sze1,ans.s1e1)));
    }
  }
  return 0;
}
