/******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <utility>
#include <queue>
#include <math.h>
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
#define N 20010
#define DEBUG 0
#define MOD 1000000007
int main(){
   int x;
   in1(t);
   vector<int> g[N];
   queue<int > q;
   bool possible=true;
   int c[N];
   ll cnt;
   fori(i,t){
      possible=true;
      cnt=1;
      in1(n);
      fori(j,n){
         g[j].clear();
      }
      fori(j,n){
         in1(k);
         fori(p,k){
            cin>>x;
            g[j].pb(x);
            g[x].pb(j);
         }
      }
      if(DEBUG)oute("input");
      mset(c,-1);
      fori(j,n){
         if(c[j]!=-1)continue;
         while(!q.empty())q.pop();
         q.push(j);
         c[j]=0;
         cnt=(cnt*2)%MOD;
         while(!q.empty()){
            int cur=q.front();
            int curVal=c[cur];
            if(DEBUG)oute(cur);
            q.pop();
            fori(p,g[cur].size()){
               int next=g[cur][p];
               if(c[next]!=-1 && c[next]==curVal){
                  possible=false;
               }
               else if(c[next]==-1){
                  q.push(next);
                  c[next]=curVal^1;
               }
            }
            if(!possible)break;
         }
         if(!possible)break;
      }
      //oute(cnt)
      if(!possible)oute(0);
      else oute(cnt%MOD);
   }
   return 0;
}
