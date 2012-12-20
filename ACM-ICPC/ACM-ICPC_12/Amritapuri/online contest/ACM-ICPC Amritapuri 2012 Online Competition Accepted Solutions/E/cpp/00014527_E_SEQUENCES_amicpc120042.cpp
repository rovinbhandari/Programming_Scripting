/******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <utility>
using namespace std;
#define fori(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define repr(i,a,b) for(int i=a; i>=b; i--)
#define foreach(i,s) for(typeof(s.begin()) i=s.begin(); i!=s.end(); i++)
#define in1(a) int (a);scanf("%d", &a)
#define ing(a) scanf("%d", &a)
#define in2(a, b) int (a),(b);scanf("%d %d", &a, &b)
#define in3(a, b, c) int (a),(b), (c);scanf("%d %d %d", &a, &b, &c)
#define mset(a,b) memset(a,b,sizeof(a))
#define outs(a) cout<<a<<" "
#define oute(a) cout<<a<<endl
#define emp(a) a.begin()==a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mi;
/******************************************************************************/
#define N 100010
#define MAX 10*N
#define DEBUG 0
int dp0[N],dp1[N],seg[MAX],xx[MAX],yy[MAX];
int mfind(int n){
   int max=1,cnt=0;
   while(max<n){
      max = max<<1;
   }
   return max;
}
int query(int a, int b , int x){
   int l=2*x, r=l+1;
   if(xx[x]>b || yy[x]<a)return -1;
   if(xx[x]>=a && yy[x]<=b)return seg[x];
   else return max(query(a,b,l), query(a,b,r));
}
int main(){
   in1(t);
   string s;
   int l,r;
   fori(i,t){
      in1(n);
      cin>>s;
      dp0[0]=(s[0]-'0')?0:1;
      rep(j,1,n-1){
         dp0[j]=dp0[j-1]+((s[j]-'0')?0:1);
      }
      dp1[n-1]=(s[0]-'0')?1:0;
      repr(j,n-2,0){
         dp1[j]=dp1[j+1]+((s[j]-'0')?1:0);
      }
      int cur=mfind(n);
      for(int j=cur; j<cur+n; j++){
         seg[j]=dp0[j-cur]+dp1[j-cur];
         xx[j]=j-cur;
         yy[j]=j-cur;
      }
      for(int j=cur+n; j<2*cur; j++){
         xx[j]=j-cur;
         yy[j]=j-cur;
         seg[j]=-1;
      }
      for(int j=cur-1; j>=1; j--){
         seg[j]=-1;
         l=2*j;
         r=l+1;
         if(seg[l]!=-1)seg[j]=max(seg[j], seg[l]);
         if(seg[r]!=-1)seg[j]=max(seg[j], seg[r]);
         xx[j]=xx[l];
         yy[j]=yy[r];
      }
      in1(q);
      fori(j,q){
         in2(a,b);
         int ret=query(a-1,b-1,1);
         ret-= dp1[b-1];
         ret-= dp0[a-1];
         if(s[b-1]=='1')ret++;
         if(s[a-1]=='0')ret++;
         oute(ret);
      }
   }
   return 0;
}
