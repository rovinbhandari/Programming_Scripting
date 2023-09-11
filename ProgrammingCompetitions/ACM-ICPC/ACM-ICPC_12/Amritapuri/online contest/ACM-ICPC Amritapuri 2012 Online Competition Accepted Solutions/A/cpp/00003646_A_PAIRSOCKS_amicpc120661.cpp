#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <iterator>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <limits.h>
# include <string.h>
#define _(x,a) memset(x,a,sizeof(x))
#define LL long long
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define GC ({ char t;scanf("%c",&t);t;})
#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forr(i,n) for(int i = (int)(n)-1; i >= 0; i--)
#define forn1(i,n) for(int i = 1; i <= (int)(n); i++)
#define forr1(i,n) for(int i = (int)(n); i >= 1; i--)
#define forit(it,x) for(it = (x).begin(); it != (x).end(); it++)
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define sz size()
#define all(x) x.begin(), x.end()
#define double long double

#define nl printf("\n");
#define si(a) scanf("%[^\n]",a);
#define sp(a) printf("\n%s",a);
#define ip(t) printf("%d\n",t);
#define cp(t) printf("%c\n",t);
using namespace std;

typedef vector<int> vi;
//typedef vector<int64> vi64;
typedef pair<int, int> pii;
//typedef pair<int64, int64> pii64;
typedef vector< vi > vvi;
typedef vector< bool > vb;
typedef vector< char > vc;
typedef vector< vb > vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector< vc > vvc;
typedef vector<double> vd;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef pair< pii, int> ppi;
typedef pair< int, pii > pip;
typedef set<int> si;
typedef map<int, vi > miv;
typedef vector< pii > vpii;
typedef map<int,int> mii;

template<typename T> T gcd(T a, T b)
{
	return b ? gcd(b, a % b) : a;
}

template<typename T> T sqr(T x)
{
	return x*x;
}

template<typename T> T cube(T x)
{
	return x * x*x;
}

int main()
{
//freopen("a.txt","r",stdin);
int t=GI;getchar();
char a[55];
while(t--)
{

    gets(a);
    //si(a);
    //puts(a);
    int cr=0,cw=0,cg=0,cb=0;
    int l=strlen(a);
    forn(i,l)
    {
        if(a[i]=='R')
            cr++;
        if(a[i]=='G')
            cg++;
        if(a[i]=='B')
            cb++;
        if(a[i]=='W')
            cw++;

    }
//    ip(cr);
//    ip(cb);
//    ip(cg);
//    ip(cw);
    if(cr%2==0 && cg%2==0 && cb%2==0 && cw%2==0)
        printf("YES\n");
    else
        printf("NO\n");
}
return 0;
}

