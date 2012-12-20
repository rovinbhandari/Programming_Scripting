
/* **** TEAM DOTCPP **** */

//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<math.h>
//some common functionn
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define FORs(i,a,b)             for(int i=a;i>=b;i--)
#define fill(a,v)               memset(a,v,sizeof a)
#define abS(x)                  ((x)<0?-(x):(x))
#define error(x)                cout << #x << " : " << (x) << endl
#define mP                      make_pair
#define pB                      push_back

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sll(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Output macros
#define p(n)                        printf("%d",n)
#define pc(n)                       printf("%c",n)
#define pll(n)                       printf("%lld",n)
#define pf(n)                       printf("%lf",n)
#define ps(n)                       printf("%s",n)

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;

using namespace std;

int main()
{
     long long t,q,i,a1,a2,a3,len,count,n,m,max;
     long long a[200000];
     cin>>t;
     for(q=0; q<t; q++)
     {
         max=0;
         count=0;
         cin>>n;
         cin>>m;
         for(i=0; i<n; i++)
         {
             cin>>a[i];
         }
         for(i=0; i<m; i++)
         {
             cin>>a1;
             cin>>a2;
             cin>>a3;
             len = (long long)(pow(a1,2)+pow(a2,2)+ pow(a3, 2));
             //len =sqrt(len);
             if(len>=max)
             max=len;
         }

         for(i=0; i<n; i++)
         {
             if(pow(a[i],2)<=max)
             count++;
         }
         cout<<count<<endl;
     }

    //system("pause");
    return 0;
}

