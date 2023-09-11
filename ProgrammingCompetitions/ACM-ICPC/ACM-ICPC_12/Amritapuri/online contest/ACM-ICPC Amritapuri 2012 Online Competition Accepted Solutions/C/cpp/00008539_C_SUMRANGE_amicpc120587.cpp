// Ideone_Language_Id:1
/* Don't remove the first line! */
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>

#ifdef __WIN32__
#define getchar_unlocked getchar
#endif
//Input-output macros
#define s(n) scan(&n)
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

/*Faster input functions*/
void scan(int* i){int t=0;char c;bool negative=false;c=getchar_unlocked();while(c<'0'||c>'9'){if(c=='-')negative=true;c=getchar_unlocked();}while(c>='0'&&c<='9'){t=(t<<3)+(t<<1)+c-'0';c=getchar_unlocked();}if(negative)t=~(t-1);*i=t;}
void scan(long long int* i){long long int t=0;char c;bool negative=false;c=getchar_unlocked();while(c<'0'||c>'9'){if(c=='-')negative=true;c=getchar_unlocked();}while(c>='0'&&c<='9'){t=(t<<3)+(t<<1)+c-'0';c=getchar_unlocked();}if(negative)t=~(t-1);*i=t;}
/*debug functions*/
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
int N, L, H;/*integers to be scanned every loop*/
int a[1010];
using namespace std;
/*functions*/

int main(int argc, char const *argv[])
{

// 	vector<int> v;
// 	v.push_back(1);v.push_back(1);v.push_back(3);v.push_back(4);v.push_back(5);
// 	int e = 2;
// 	int tt = int(upper_bound(all(v), e-1) - v.begin());
// 	if(!binary_search(all(v), e))
// 		tt--;
// 	debug(tt);
// return 0;


	/* code */
	s(T);
	while(T--)
	{
		int sum = 0;
		s(N);s(L);s(H);
		for (int i = 0; i < N; ++i)
		{
			s(a[i]);
		}
		vector<int> vec(a, a+N);
		sort(all(vec));
		//debug(vec);
		int res_num = 0;
		for (int i = 0; i < N; ++i)
		{
			int sum1 = vec[i]<<1; //twice
			for (int j = i+1; j < N; ++j)
			{
				sum1 = sum1+(vec[j]-vec[j-1]); //sequencial accesses.
				int sum2 = sum1;
				//debug(sum2);
				int l = L - sum2, h = H - sum2;
				if(h < 0)
					continue;
				if(l < 0)
					l = 0;
				vector<int>::iterator it = upper_bound(vec.begin() + j + 1, vec.end(), l);
				int lIndex = it - vec.begin();
				if(lIndex != 0 &&vec[lIndex - 1] == l)
					lIndex--;
				it = upper_bound(vec.begin() + j + 1, vec.end(), h-1);
				int hIndex = it - vec.begin();
				if(!binary_search(vec.begin() + j + 1, vec.end(), h))
					hIndex--;
				if(hIndex == vec.size())
					hIndex--;
				int range = hIndex - lIndex + 1;
				if(i <= hIndex && i >= lIndex)
					range--;
				if(j <= hIndex && j >= lIndex)
					range--;
				//debug(l, h, lIndex, hIndex, range);
				// for (int ii = lIndex; ii <= hIndex; ++ii)
				// {
				// 	if(ii == 1 || ii == j)
				// 		continue;
				// 	debug(i, j, ii);
				// }
				sum += range;
			}
		}
		//p(res_num);
		p(sum);
	}
	return 0;
}
