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

int main()
{
    int t;
    scanf("%d",&t);
    char a[100];
    int h[10];
    while(t--)
    {
              int i;
              scanf("%s",&a);
              clr(h);
              for(i=0;i<strlen(a);++i)
              {
                                      if(a[i]=='R')
                                      h[0]+=1;
                                      else if(a[i]=='G')
                                      h[1]+=1;
                                      else if(a[i]=='B')
                                      h[2]+=1;
                                      else if(a[i]=='W')
                                      h[3]+=1;
                                      }
              int flag=0;
              for(i=0;i<4;++i)
              {
                              if(h[i]&1)
                              flag=1;
                              }
              if(flag==1)
              printf("NO\n");
              else
              printf("YES\n");
              }
return 0;
}
