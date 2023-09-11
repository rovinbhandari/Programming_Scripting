#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define FOR(i,a,b)				for(int i=a;i<b;i++)
#define REP(i,n)				FOR(i,0,n)
#define foreach(v,c)			for(typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define FF						first
#define SS						second
#define tri(a,b,c)				mp(a,mp(b,c))
#define XX						first
#define YY						second.first
#define ZZ						second.second
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define SZ(v)					((int)(v.size()))
#define DREP(a)					sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())
#define debug(args...)			{dbg,args; cerr<<endl;}
#define dline					cerr<<endl

void sc(char &c){
	char temp[4];
	ss(temp);
	c=temp[0];
}

struct debugger{
	template<typename T> debugger& operator , (const T& v){	
		cerr<<v<<" ";
		return *this;
	}
} dbg;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;

//Main Code Starts

int main(){
	int tc, len;
	char s[51];
	
	s(tc);

	map<char,int> count;

	while(tc--){
		ss(s);
		len = strlen(s);

		count.clear();
		count['R'] = 0;
		count['G'] = 0;
		count['B'] = 0;
		count['W'] = 0;

		REP(i,len){
			count[s[i]]++;
		}

		if(count['R']%2 == 0 &&  count['G']%2 == 0 && count['B']%2 == 0 && count['W']%2 == 0){
			printf("YES\n");
		} else{
			printf("NO\n");
		}
	}

	return 0;
}
