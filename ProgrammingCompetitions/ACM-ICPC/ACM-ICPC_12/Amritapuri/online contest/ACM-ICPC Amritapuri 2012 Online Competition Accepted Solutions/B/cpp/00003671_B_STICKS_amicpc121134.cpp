#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cfloat>
#include <climits>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <sys/time.h>

#define INF 1000000007
#define EPS (1e-8)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define mp make_pair
#define FOR(i,k) for(i=0;i<k;i++)
#define RFOR(i,k) for(i=k-1;i>=0;i--)
const long double PI = 3.1415926535897932384626433832795;
typedef long long LL;


using namespace std;


class Rename
{
public:
};


main()
{
  int tests;
  scanf("%d",&tests);

  LL sticks;
  LL boxes;
  LL L[50009] , a,b,c;
  
  while( tests-- > 0 )
    {
      scanf("%lld%lld",&sticks,&boxes);
      
      for( int i = 0 ; i< sticks ; i++ )
	{
	  scanf("%lld",&L[i]);
	}

      LL maxlensqr = 0;
      for( int i = 0 ; i < boxes ; i++ )
	{
	  scanf("%lld%lld%lld",&a,&b,&c);
	  maxlensqr = max ( maxlensqr , ( a*a + b*b + c*c ) );
	}

      LL count = 0;
      for( int i = 0 ; i < sticks ; i++ )
	{
	  if( L[i]*L[i] <= maxlensqr )
	    {
	      count++;
	    }
	}

      printf("%lld\n",count);
    }
}
