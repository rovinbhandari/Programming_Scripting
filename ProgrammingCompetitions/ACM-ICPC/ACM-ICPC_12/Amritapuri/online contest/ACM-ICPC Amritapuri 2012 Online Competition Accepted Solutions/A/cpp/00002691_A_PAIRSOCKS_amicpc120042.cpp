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

int main(){
   in1(t);
   string s;
   int r,b,w,g;
   fori(i,t){
      cin>>s;
      r=b=w=g=0;
      fori(j,s.length()){
         if(s[j]=='R')r++;
         else if(s[j]=='G')g++;
         else if(s[j]=='B')b++;
         else w++;
      }
      if(r%2 || b%2 || w%2 || g%2)oute("NO");
      else oute("YES");
   }
   return 0;
}
