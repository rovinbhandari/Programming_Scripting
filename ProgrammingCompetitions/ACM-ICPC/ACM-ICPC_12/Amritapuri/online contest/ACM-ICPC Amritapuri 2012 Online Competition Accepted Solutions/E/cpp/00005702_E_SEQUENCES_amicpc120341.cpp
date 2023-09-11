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
using namespace std;
# define MAXN 100100

struct node
{
  int z,o,t;
  /*
  node() { z = o = t = -1; }
  node(int _z, int _o, int _t) : z(_z), o(_o), t(_t) {}
  */
}INF;


char S[MAXN];
node M[3 * MAXN];
int start, end;
bool A[MAXN];
int n,q;

int mx(int a, int b)
{
  if(a > b)
    return a;
  else return b;
}

node func(node a, node b)
{
  node c;
  c.z = a.z + b.z;
  c.o = a.o + b.o;

  c.t = mx(a.t + b.o, a.z + b.t);
  c.t = mx(c.t, a.z + b.o);
  return c;
}

void initbla(int idx, int lo, int hi)
{
  if(lo > hi) return;

  if(lo == hi)
    {
      int z = 0, o = 0;
      if(A[lo])
	o = 1;
      else z = 1;
      M[idx].z = z;
      M[idx].o = o;
      M[idx].t = 1;
      return;
    }

  int Left = 2 * idx + 1;
  int Right = 2 * idx + 2;
  int mid = (lo + hi) / 2;
  
  initbla(Left, lo, mid);
  initbla(Right, mid + 1, hi);
  M[idx] = func(M[Left], M[Right]);
}


node querybla(int idx, int lo, int hi)
{
  if(lo > hi) return INF;

  if(lo > end || hi < start) return INF;

  if(lo >= start && hi <= end) return M[idx];

  int Left = 2 * idx + 1;
  int Right = 2 * idx + 2;
  int mid = (lo + hi) / 2;

  node v1 = querybla(Left, lo, mid);
  node v2 = querybla(Right, mid + 1, hi);

  if(v1.z == -1) return v2;
  if(v2.z == -1) return v1;
  
  return func(v1, v2);
}

int main()
{
  int t,i;
  node val;
  scanf("%d", &t);

  INF.z = -1;
  INF.o = -1;
  INF.t = -1;
  while(t--)
    {
      scanf("%d", &n);
      scanf("%s", S);
      for(i = 0; S[i]; i++)
	{
	  A[i] = (S[i] == '0') ? false : true;
	}

      initbla(0, 0, n - 1);
      scanf("%d", &q);
      for(i = 0; i < q; i++)
	{
	  scanf("%d %d", &start, &end);
	  start--;
	  end--;
	  val = querybla(0, 0, n - 1);
	  printf("%d\n", val.t);
	}
    }

  return 0;
}
