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

int main(){
	int n;
	ri(n);
	string t;
	while(n--){
		cin>>t;
		int l=t.length();
		int a,b,c,d;
		a=b=c=d=0;
		f(i,0,l){
			if(t[i]=='R')a++;
			if(t[i]=='G')b++;
			if(t[i]=='B')c++;
			if(t[i]=='W')d++;
		}
		if(a%2==0&&b%2==0&&c%2==0&&d%2==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}



