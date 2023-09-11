#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>

//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<complex>
#include<string>
#include<stack>
#include<bitset>
#include<istream>
#include<valarray>

//IOs
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<exception>
#include<ios>
#include<iosfwd>
#include<ostream>
#include<iterator>
#include<stdexcept>
#include<streambuf>


//algorithm & miscellaneous
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#define ll long long
#define ull unsigned long long
#define mod 1000000007ll
#define fill(x) memset(x,0,sizeof x)
#define inf (ll)1e18
#define iinf (int)1e9

using namespace std;

ll a[5000000];
int main()
{
          int t;
          scanf("%d",&t);
          
          while(t--)
          {
                                  int n,m;
                                  scanf("%d %d",&n,&m);
                                  
                                  
                                  
                                  for(int i=0;i<n;i++)
                                  {
                                           scanf("%d",&a[i]);
                                               
                                  }
                                  
                                  sort(a,a+n);
                                  
                                  ll x,y,z,max1=0;
                                  
                                  for(int i=0;i<m;i++)
                                  {
                                          scanf("%lld %lld %lld",&x,&y,&z);  
                                          max1=max(max1,(ll)sqrt(x*x+y*y+z*z)); 
                                  }
                                   
                                   ll cnt=0;
                                   for(int i=n-1;i>=0;i--)
                                   {
                                           if(a[i]<=max1){cnt=i+1;break;}
                                   }
                                   
                                   printf("%lld\n",cnt);
          }          
          return 0;
}
