
#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <sstream>
#include <map>
#include <set>
#include <climits>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define INF 1000000000
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef long long LL;
int main()
{
   int i,j,t,n,m,c;
   long long int l,b,h,hyp,maxi,ars[50001];
   cin>>t;
   while(t--){
      scanf("%d%d",&n,&m);
      for(i=0;i<n;i++)
	 scanf("%lld",&ars[i]);
      maxi=0;c=0;
      for(j=0;j<m;j++){
	 scanf("%lld%lld%lld",&l,&b,&h);
	 hyp=l*l+b*b+h*h;
	 maxi=max(maxi,hyp);
      }
      for(i=0;i<n;i++){
	 if(ars[i]*ars[i]<=maxi)
	    c++;
      }
      cout<<c<<endl;
   }
	return 0;
}
