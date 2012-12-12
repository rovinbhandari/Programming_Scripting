
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
   int t,i,rc,wc,gc,bc;
   string st;
   cin>>t;
   while(t--){
      rc=0;wc=0;gc=0;bc=0;
      cin>>st;
      for(i=0;i<st.size();i++){
	 if(st[i]=='R')
	    rc++;
	 else if(st[i]=='W')
	    wc++;
	 else if(st[i]=='B')
	    bc++;
	 else if(st[i]=='G')
	    gc++;
      }
      if(gc%2==0&&rc%2==0&&wc%2==0&&bc%2==0)
	 cout<<"YES"<<endl;
      else
	 cout<<"NO"<<endl;
   }
   return 0;
}
