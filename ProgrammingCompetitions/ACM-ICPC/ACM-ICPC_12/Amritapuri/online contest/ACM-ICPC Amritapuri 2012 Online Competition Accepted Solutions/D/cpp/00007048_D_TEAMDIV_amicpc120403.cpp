/*************
	Team - ThePrestige
****************/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

#define rep(i,a,b) for(typeof(a) i=(a);i<(b);i++)
#define ll long long int
#define ii pair<int,int>
#define gi(x) scanf("%d",&x)
#define Clear(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()
#define MOD 1000000007
#define MAX 30000

int a[MAX];
int mark[MAX];
int pre[MAX];
vector< vector<int> > vv(MAX);

bool okay( int i , bool fl ) {
	if( mark[i] == fl ) return true;
//	cout<< i<<"\n";
	if( mark[i] == -1 ) { 
		mark[i] = fl;
		int sz = vv[i].size();bool ret = true;
		rep( ind , 0 , sz ) {
			int v = vv[i][ind];
			ret = ret&okay(v , !fl);
		}
		return ret;
	}
	return false;
}
int main()
{
	int T; gi(T);
	while( T-- ) {
		rep( i , 0 , MAX ) vv[i].clear();

		int N; gi(N);
		rep( i , 0 , N ) {
			int K; gi(K);
			rep( j , 0 , K ){  int riv; gi(riv); vv[i].push_back(riv);vv[riv].push_back(i); }
		}
		Clear( mark , -1 );
		ll ans = 1;
		rep( i , 0 , N ) if( mark[i] == -1 ) { if(okay(i,0)) ans *= 2; else ans *= 0;  ans %= MOD; }		
		cout << ans << "\n";
	}	
	return 0;
}
