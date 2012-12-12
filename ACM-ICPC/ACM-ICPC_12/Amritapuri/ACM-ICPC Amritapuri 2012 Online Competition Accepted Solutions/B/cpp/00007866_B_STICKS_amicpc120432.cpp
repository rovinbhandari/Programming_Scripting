//pushap ka daddy
#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <string>

#define all(i,n) for(i = 0; i < (n); i++)
#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p,0,sizeof(p))
#define maX(a,b) ((a)>(b)?(a):(b))
#define miN(a,b) ((a)<(b)?(a):(b))
#define S(n) scanf("%d",&n)
#define P(n) printf("%d\n",n)
#define Sl(n) scanf("%lld",&n)
#define Pl(n) printf("%lld\n",n)
#define Sf(n) scanf("%lf",&n)
#define Ss(n) scanf("%s",n)
#define LL long long
#define ULL unsigned long long
#define pb push_back
#define mod 1000000007
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
            long long  int arr[50005]={0};
             long long  int n,m,a,b,c,i;
               long long counter=0;
               long long maxd=0;
              scanf("%lld",&n);
              scanf("%lld",&m);
              for(i=0;i<n;i++)
              {
                              scanf("%lld",&arr[i]);
              }
              for(i=0;i<m;i++)
               {scanf("%lld",&a);
                scanf("%lld",&b);
                 scanf("%lld",&c);
                 long long ga=a*a + b*b +c*c;
                 long long num=(long long)(sqrt(ga));
                 //printf("num=%lld\n",num);
                 if(num>maxd)
                 maxd=num;
               }
             //  printf("Max==%d",maxd);

             //  printf("hghsa%d\n",arr[0]);
               for(i=0;i<n;i++)
               {
                             //  printf("arr=%d\n",arr[i]);
                               if(arr[i]<=maxd)
                               counter++;
               }
               printf("%lld\n",counter);
    }

 return 0;
}
