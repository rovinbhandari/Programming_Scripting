#include <cstdio>
#include <iostream>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <ctime>
using namespace std;
 
# define f(i,a,b) for(int i=a;i<b;i++)
# define TT "\t"
# define Clear(x) memset(x,0,sizeof(x))
# define fill(x,a) memset(x,a,sizeof(x))
# define pb push_back
# define mp make_pair
# define X first
# define Y second
# define inf 2147000000
# define linf 9223372036854770000LL
# define sqr(x) ((x)*(x))


typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector < pair<int, int > > vii;
typedef vector<int> vi;

template <class T>
inline void ri(T &i){
bool minus=false;
char c;for(c=getchar();(c<'0'||c>'9')&&(c!='-');c=getchar());
if(c=='-'){minus=true;c='0';}
for(i=0;c>='0'&&c<='9';c=getchar())
i=(i<<3)+(i<<1) + (c-48);
if(minus)i=(~i)+1;
}


void input(){
}
int main(){
	input();
	int n,m;
	int test;cin>>test;
	while(test--){
	
	ri(n);ri(m);
	ll in[n];
	f(i,0,n){
		ri(in[i]);
	}
	
	ll l[m],b[m],h[m];
	f(i,0,m){
		ri(l[i]);ri(b[i]);ri(h[i]);
	}
	
	double ma=0;
	double x,y,z;
	f(i,0,m){
		x=sqrt((double)sqr(l[i]) +sqr(b[i]));
		y=sqrt((double) sqr(x) +sqr(h[i]) );
		ma=max(ma,y);
//		cout<<y<<endl;
//		cout<<ma<<endl;
	}
	
	int cnt=0;
	f(i,0,n){
		x=in[i];
		if(x<=ma)cnt++;
	}
	
	cout<<cnt<<endl;
	}
	return 0;
}







