#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
/*more #includes. Don't write "using namespace std" here*/
#include <cstdio>

//Input-output macros
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define p(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define sf(n) scanf("%f",&n)
#define pf(n) printf("%f\n",n)
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c\n",n)
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s\n",n)
// Useful constants
#define INF (int)1e9
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd
// Useful container manipulation / traversal macros
#define forall(i,a,b) for(int i=a;i<b;i++)
#define foreach(v,c) for(typeof((c).begin()) v=(c).begin();v!=(c).end();++v)
#define all(a) a.begin(),a.end()
#define in(a,b) ((b).find(a)!=(b).end())
#define pb push_back
#define fill(a,v) memset(a,v,sizeof a)
#define sz(a) ((int)(a.size()))
#define mp make_pair
// Some common useful functions
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define checkbit(n,b) ((n>>b)&1)
#define DREP(a) sort(all(a));a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())

#ifdef DEBUG
	#define debug(args...) {dbg,args;std::cerr<<std::endl;}
#else
	#define debug(args...) // Just strip off all debug tokens
#endif
struct debugger{template<typename T> debugger& operator ,(const T& v){std::cerr<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline std::ostream& operator<<(std::ostream& os,const std::pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline std::ostream&operator<<(std::ostream& os,const std::vector<T>& v){bool first=true;std::string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline std::ostream&operator<<(std::ostream& os,const std::set<T>& v){bool first=true;std::string delim="[";for (typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline std::ostream&operator<<(std::ostream& os,const std::map<T1,T2>& v){bool first=true;std::string delim="[";for (typename std::map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}

/*structs and typedefs*/

int T;/*number of test cases*/
/*integers to be scanned every loop*/
/*more global variables*/
using namespace std;
/*functions*/
#include<cmath>
int main(int argc, char const *argv[])
{
	/* code */
	s(T);
	long long L[50005];
	while(T--)
	{
		//ss(arr);
		int n=0,m=0;
		s(n);
		s(m);
		forall(i,0,n)
			sl(L[i]);
		long long maxi=-1;
		long long a,b,c;
		forall(i,0,m){
			sl(a);sl(b);sl(c);
			long long dia=a*a+b*b+c*c;
			if(dia>maxi)
				maxi=dia;
			//cout<<maxi<<"\n";

		}
		long long count=0;
		forall(i,0,n){
			if(L[i]*L[i]<=maxi+0LL)
				count++;
		}
		printf("%lld\n",count);
	}
	
	return 0;
}
