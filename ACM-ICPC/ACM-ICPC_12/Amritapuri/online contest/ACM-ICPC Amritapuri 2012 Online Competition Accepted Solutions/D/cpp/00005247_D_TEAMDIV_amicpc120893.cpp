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

vector <int> in[20003];
vector <int> out[20003];
int n;
int visited[20003];
int k;
void input(){
	ri(n);
	Clear(visited);
	f(i,0,20003){in[i].clear();out[i].clear();}
	k=0;
	//reseted;
	int t;int x;
	f(i,0,n){
		ri(t);
		f(j,0,t){
			ri(x);
			out[i].pb(x);
			in[x].pb(i);
		}
	}
	//graph is done
	
	
}
int flag;
int dfs(int no,int a){
	visited[no]=a;int b=1;
	if(a==1)b=2;
	f(i,0,in[no].size()){
		int cur=in[no][i];
		if(visited[cur]==a)flag=1;
		if(visited[cur]==0)dfs(cur,b);
	}
	f(i,0,out[no].size()){
		int cur=out[no][i];
		if(visited[cur]==a)flag=1;
		if(visited[cur]==0)dfs(cur,b);
	}
}
#define mod 1000000007

int main(){
	int test;cin>>test;
	while(test--){
		input();
		//do a dfs;
		flag=0;
		f(i,0,n){
			if(visited[i]==0){
				dfs(i,1);k++;
			}
		}
		
		if(flag){
			cout<<"0"<<endl;
		}
		else{
			ll ans=1;
			f(i,0,k){
				ans=(ans*2)%mod;
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}



