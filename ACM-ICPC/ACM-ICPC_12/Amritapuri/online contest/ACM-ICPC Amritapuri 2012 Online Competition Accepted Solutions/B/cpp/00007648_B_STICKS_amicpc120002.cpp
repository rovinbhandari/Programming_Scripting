#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

#define clr(a) memset(a,0,sizeof(a))
#define set(a) memset(a,-1,sizeof(a))
#define R(a) freopen(a,"r",stdin)

template <class T> T gcd(T a, T b) { return b==0 ? a : gcd(b,a%b) ; }
template <class T> T maxm(T a, T b) { return a > b ? a : b ; }
template <class T> T minm(T a, T b) { return a < b ? a : b ; }
template <class T> T abs(T a) { return a > 0 ? a : (-1)*a ; }
template <class T> T sq(T a) { return a * a ; }

long long d[50005];
long long l[50005],b[50005],h[50005],a[50005];

int main()
{
    int t,cnt,n,m,max,i;
    scanf("%d",&t);
    while(t--)
    {
              cnt=0;
              scanf("%d%d",&n,&m);
              for(i=0;i<n;++i)
              scanf("%lld",&a[i]);
              max=0;
              for(i=0;i<m;++i)
              {
                              scanf("%lld%lld%lld",&l[i],&b[i],&h[i]);
                              d[i]=(long long)sqrt(l[i]*l[i]+b[i]*b[i]+h[i]*h[i]);
                              if(max<d[i])
                              {
                                     max=d[i];     
                                          }
                              }
                              
              for(i=0;i<n;++i)
              {
                              if(a[i]<=max)
                              {
                                            cnt++;
                                            }
                              }            
              printf("%d\n",cnt);  
              }
return 0;

}
