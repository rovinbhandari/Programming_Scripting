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
  
  int r,g,b,w;

  char str[100];
  while( tests-- > 0 )
    {
      scanf("%s",str);
      
      int len = strlen( str );

      r = 0;
      g = 0;
      b = 0;
      w = 0;

      for( int i = 0 ; i < len ; i++ )
	{
	  if( str[i] == 'R' )
	    {
	      r++;
	    }
	  else if( str[i] == 'G' )
	    {
	      g++;
	    }
	  else if( str[i] == 'B' )
	    {
	      b++;
	    }
	  else if( str[i] == 'W' )
	    {
	      w++;
	    }
	}

      bool valid = true;
      if( ( r %2 ) == 1 )
	{
	  valid = false;
	}

      if( ( g %2 ) == 1 )
	{
	  valid = false;
	}

      if( ( b %2 ) == 1 )
	{
	  valid = false;
	}

      if( ( w %2 ) == 1 )
	{
	  valid = false;
	}
      
      if( valid )
	{
	  printf("YES\n");
	}
      else
	{
	  printf("NO\n");
	}
    }
}


      


