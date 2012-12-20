# include <iostream>
# include <cstdio>
# include <vector>
# include <set>
# include <map>
# include <bitset>
# include <algorithm>
# include <string>
# include <cstring>
# include <sstream>
# include <cstdlib>
# include <queue>
# include <stack>
# include <cmath>
using namespace std;
# define MAXM 50100



double A[MAXM];
vector<int> L;
int n,m;

void calc()
{
  vector<int>::iterator it;
  int Ans;
  int i,v;
  int idx;
  Ans = 0;
  for(i = 0; i < m; i++)
    {
      v = floor(A[i]);
      it = upper_bound(L.begin(), L.end(), v);
      idx = (int)(it - L.begin());
      Ans = max(Ans, idx);
    }
  printf("%d\n", Ans);
}


int main()
{
  long long l,b,h;
  int a,i;
  int t;
  scanf("%d", &t);
  while(t--)
    {
      L.clear();
      scanf("%d %d", &n, &m);
      for(i = 0; i < n; i++)
	{
	  scanf("%d", &a);
	  L.push_back(a);
	  
	}
      sort(L.begin(), L.end());

      for(i = 0; i < m; i++)
	{
	  scanf("%lld %lld %lld", &l, &b, &h);
	  A[i] = sqrt(l * l + b * b + h * h);
	}
      sort(A, A + m);
      calc();
    }

  return 0;
}
