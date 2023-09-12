
// Time starts NOW !!

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#include <climits>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <list>
#include <complex>

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef pair<double,double> pdd;
typedef vector<vector<pair<int, int> > > WGraph;
typedef priority_queue<int> MXHEAP;
typedef priority_queue<int,vi,greater<int> > MNHEAP;

// Useful container manipulation / traversal macros
#define pb		push_back
#define mp	 	make_pair
#define sz(v)		(int)(v.size())
#define all(x)		x.begin(), x.end()
#define tr(c,i) 	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define cpresent(c,x) 	((c).find(x) != (c).end())
#define vpresent(c,x) 	(find(all(c),x) != (c).end())
#define FF		first
#define SS		second

// loops
#define T(t)            int t;scanf ("%d",&t);while (t--)
#define forall(i,a,b)	for(int i=a;i<b;i++)
#define FOR(i,a,b)	for(int i=a;i<b;i++)
#define REP(i,n)	FOR(i,0,n)

// inputs
#define s(n)            scanf("%d",&n)
#define sf(n)           scanf("%lf",&n)
#define ss(n)           scanf("%s",n)

// Useful constants
#define INF             (int)1e9
#define EPS 		1e-9
#define LINF		(long long)1e18
const int rx[]={0,-1,0,1,-1,1, 1,-1};
const int cy[]={1,0,-1,0, 1,1,-1,-1};
//              U  L D R LU UR DR RL


// Useful hardware instructions
#define hwbitcount    	__builtin_popcount
#define hwgcd      	__gcd

// Some common useful functions
#define fill(a,v) 	memset(a, v, sizeof(a))
#define checksqrt(n)    (typeof(n))sqrt(n)*(typeof(n))sqrt(n)==n
#define DREP(a)     	sort(all(a)); a.erase(unique(all(a)),a.end())
#define maximum(a) 	(*max_element(all(a)))
#define minimum(a) 	(*min_element(all(a)))
#define INDEX(arr,ind)	(lower_bound(all(arr),ind)-arr.begin())

// Split
//template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}



int main()
{
    int t ;
    scanf("%d",&t) ;
    while (t--)
    {
        int n,m ;
        cin >> n >> m ;
        vector <long long int> L(n,0) ;
        for (int i = 0 ; i< n ; i++)
        {
            scanf("%lld",&L[i]) ;
        }
        long long int ma = 0 ;
        long long int a,b,c;
        for (int i = 0 ; i < m ;i++)
        {
            scanf("%lld%lld%lld",&a,&b,&c) ;
            ma = max(ma,(long long int)(a*a + b*b + c*c)) ;
        }
        int cnt =0 ;
        for (int i =0 ; i < n ;i++)
        {
            long long int x = L[i]*L[i];
            if (x <= ma )
            {
                cnt++;
            }
        }
        cout  << cnt << endl ;
    }
    return 0;
}
