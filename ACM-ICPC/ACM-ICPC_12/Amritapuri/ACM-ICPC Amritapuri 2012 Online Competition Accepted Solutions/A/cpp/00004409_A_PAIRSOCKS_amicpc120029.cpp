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
#include<cmath>
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
int test,temp,x;
cin>>test;
char a[100];

getchar();
while(test--)
{
             gets(a);
             int b[4]={0};
             if(strlen(a)==0 || strlen(a)==1)
             {
                             cout<<"NO"<<endl;
                             continue;}
             for(int i = 0;i < strlen(a);i++)
             {
                     if(a[i]=='R')
                     b[0]++;
                     else if(a[i]=='G')
                     b[1]++;
                     else if(a[i]=='B')
                     b[2]++;
                     else if(a[i]=='W')
                     b[3]++;
             }
             bool flag = true;
             for(int i = 0;i <4;i++)
             {
                     if(b[i]%2!=0)
                     { flag = false;
                        break;
                     }
             }
                       if(flag==true)
                       cout<<"YES"<<endl;
                       else
                       cout<<"NO"<<endl;
                       }
    return 0;
}

