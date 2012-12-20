// Author: Nishant R. Krishan
#include <iostream>
#include <sstream>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>

using namespace std;
#define VI vector < int >
#define VVI(A,N,M) vector< VI > A( N, VI (M) )
#define LL long long
#define LLU unsigned long long int
#define SI ({int x;scanf("%d",&x);x;})
#define SC ({char x;scanf("%c",&x);x;})
#define SLL ({LL x;scanf("%lld",&x);x;})
#define SLLU ({LLU x;scanf("%llu",&x);x;})
#define PI acos(-1)
#define ALL(c) (c).begin(), (c).end() 
#define SORT(c) sort(ALL(c)) 
#define X first 
#define Y second
#define MP make_pair
#define PB push_back
#define SET(v,i) memset(v, i, sizeof(v))
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (a); i > (b); i--)
#define FORN(i,a,b) for (int i = (a); i <= (b); i++)
#define DOWN(i,a,b) for (int i = (a); i >= (b); i--)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define INF 1000000007

int N,flag;
vector<int> G[20001];
bool used[20001];
int color[20001];
LL Ans;

LL Calc( LL X ){
	if( X==0 )
		return 0;
	if( X==1 )
		return 2;
	LL Tmp = Calc( X/2 );
	Tmp = (Tmp*Tmp)%INF;
	if( X&1 )
		Tmp = (Tmp*2)%INF;
	return Tmp;
}

void dfs( int v, int col ){
	int i,to;
	used[v]=true;
	if( (color[v]==-1) || (color[v]==col ) ){
		color[v]=col;
	}
	else{
		flag=1;
		return;
	}

	for( i=0;i<G[v].size();++i ){
		to = G[v][i];
		if( !used[to] )
			dfs(to,(col+1)%2);
		else{
			if( color[to]==color[v] ){
				flag=1;
				return;
			}
		}
	}
}

int main(int argc, char** argv) {
	int T=SI,K,i,j,Tmp;
	while( T-- ){
		N=SI;
		Ans=0;
		flag=0;
		for( i=0;i<N;i++ )
			G[i].clear();
		for( i=0;i<N;i++ ){
			K=SI;
			for( j=0;j<K;j++ ){
				Tmp = SI;
				G[i].PB(Tmp);
				G[Tmp].PB(i);
			}
		}
		for( i=0;i<N;i++ ){
			used[i]=false;
			color[i]=-1;
		}

		for( i=0;i<N;i++ ){
			if( used[i]==false ){
				dfs(i,0);
				if( flag==1 )
					break;
				Ans++;
			}
		}
		Ans = Calc( Ans );
		printf("%lld\n",Ans);
	}
	return 0;
}

