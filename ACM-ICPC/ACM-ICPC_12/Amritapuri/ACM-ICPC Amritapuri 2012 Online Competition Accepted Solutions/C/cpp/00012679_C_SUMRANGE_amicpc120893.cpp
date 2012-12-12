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

ll n,l,h;
vector <ll >a;
void input(){
	ri(n);ri(l);ri(h);
	int t,x;
	a.clear();
	
	f(i,0,n){
		ri(t);
		a.pb(t);
	}
	sort(a.begin(),a.end());
	
}


ll calcul(){
	ll sum,key;ll ans=0;ll k;
	f(i,0,n){
		k=n-1;
		f(j,i+1,k){
			sum=a[i]+a[j];
			if(sum+a[k]<l)continue;
			
			while(k>j+1&&a[k-1]+sum>=l){
				k--;
			}
			ans+=n-k;
		}
		if(a[i]+a[k]+a[k+1]>l){
		ans+=((n-k)*(n-k-1))/2;
		}
	}
	
	ll ans1=0;l=h+1;
	f(i,0,n){
		k=n-1;
		f(j,i+1,k){
			sum=a[i]+a[j];
			if(sum+a[k]<l)continue;
			while(k>j+1&&a[k-1]+sum>=l){
				k--;
			}
			ans1+=n-k;
			
		}
		if(a[i]+a[k]+a[k+1]>l)
		ans1+=((n-k)*(n-k-1))/2;
		
	}
	
	return ans-ans1;
}
int main(){
	int test;cin>>test;
	while(test--){
		input();
		cout<<calcul()<<endl;;
	}	
	return 0;
}


	
