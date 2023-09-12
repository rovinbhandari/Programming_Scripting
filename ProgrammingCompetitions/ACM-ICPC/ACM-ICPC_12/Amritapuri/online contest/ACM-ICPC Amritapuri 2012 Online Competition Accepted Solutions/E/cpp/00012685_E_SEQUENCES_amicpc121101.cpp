#include <vector>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <climits>
#include <limits>
using namespace std;
//Macros
#define SIZE(A) ((int)(A.size()))
#define SET(A,x) memset(A,x,sizeof(A));                 //NOTE: Works only for x = 0 and -1. Only for integers.
#define FILL(A,x) fill(A.begin(),A.end(),x)
#define REP(i,N) for(int i=0;i<(int)(N);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define REV(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(x)  x.begin(),x.end()
#define INF (INT_MAX/2)
#define LLINF (LONG_LONG_MAX/2LL)
#define EPS 1e-11
#define GI ({int t;scanf("%d",&t);t;})                  //NOTE: Don't comma separate two inputs.
#define GL ({long long t;scanf("%lld",&t);t;})          //NOTE: Don't comma separate two inputs.
#define GF ({double t;scanf("%lf",&t);t;})              //NOTE: Don't comma separate two inputs.
#define MP make_pair
#define PB push_back
#define gcd(a,b) __gcd(a,b)                             //NOTE: Both the arguments should be of the same type.
#define nbits(n) __builtin_popcount(n)                  //NOTE: Works only for int. Write your own function for long long :-/
#define MOD 1000000007
#define MAXN 100005
#define FIX(a) (((a)%MOD+MOD)%MOD)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
#define SUBMIT false                                    //NOTE: Set this to true before submitting
#define   debug(x)              if(!SUBMIT){ cout<<"-> "<<#x<<" = "<<x<<"\n";}
#define   debugv(x)             if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x))cout<<x[i]<<" ";cout<<"\n";}
#define   debugvv(x)            if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x)){REP(j,SIZE(x[i])){cout<<x[i][j]<<" ";}cout<<"\n";}}
#define   debug1(A,N)           if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,N)cout<<A[i]<<" ";cout<<"\n";}
#define   debug2(A,R,C)         if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,R){REP(j,C){cout<<A[i][j]<<" ";}cout<<"\n";}}

//Main code starts here
char s[MAXN]; 
int zeroxxx[MAXN];
int ones[MAXN];
int n, q; 
int N; 


int cnt(int a, int k, int b) {
    return zeroxxx[k-1] - zeroxxx[a-1] + ones[b] - ones[k-1]; 
}

int A[MAXN];
int M[MAXN][20];

void sparsetable()
{
	int i, j;
	for (i = 0; i < N; i++)
		M[i][0] = i;
	for (j = 1; 1 << j <= N; j++)
		for (i = 0; i + (1 << j) - 1 < N; i++)
			if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
				M[i][j] = M[i][j - 1];
			else
				M[i][j] = M[i + (1 << (j - 1))][j - 1];
}  

int rmq(int i, int j)
{
	int k = floor(log(j-i+1) / log(2));
	if(A[M[i][k]] <= A[M[j-(1<<k)+1][k]])
		return M[i][k];
	return M[j-(1<<k)+1][k];
}

int main()
{
    int t = GI;
    while(t--) {
        cin >> n; 
        N = n+1;
        scanf("%s", s); 
        memset(zeroxxx, 0, sizeof(zeroxxx)); 
        memset(ones, 0, sizeof(ones)); 
        REP(i,n) {
            if (s[i] == '0')
                zeroxxx[i+1] = 1;
            else
                ones[i+1] = 1; 
        }
        for (int i = 1; i <= n + 1; i ++) {
            zeroxxx[i] += zeroxxx[i-1];
            ones[i] += ones[i-1]; 
        }

        REP(i, n+1) A[i] = -zeroxxx[i] + ones[i];
        sparsetable();

        cin >> q;
        while (q --) {
            int a = GI; 
            int b = GI; 
            int loc = rmq(a-1, b);

            //cout<<a<<" "<<(loc+1)<<" "<<b<<endl;
            printf("%d\n", cnt(a, loc+1, b)); 
        }
    }
	return 0;
}
