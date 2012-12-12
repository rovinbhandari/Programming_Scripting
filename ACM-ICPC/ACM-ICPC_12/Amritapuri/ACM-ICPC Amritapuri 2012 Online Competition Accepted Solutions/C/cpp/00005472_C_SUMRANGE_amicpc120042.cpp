/******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <utility>
#include <fstream>
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
#define N 1010
int main(){
   in1(t);
   int a[N];
   fori(i,t){
      in3(n,l,h);
      fori(j,n){
         ing(a[j]);
      }
      sort(a,a+n);
      int cnt=0;
      fori(j,n-2){
         rep(k,j+1,n-2){
            int lo=l-a[j]-a[k];
            int hi=h-a[j]-a[k]+1;
            cnt +=lower_bound(a+k+1,a+n,hi)-lower_bound(a+k+1,a+n,lo);
         }
      }
      oute(cnt);
   }
   return 0;
}
