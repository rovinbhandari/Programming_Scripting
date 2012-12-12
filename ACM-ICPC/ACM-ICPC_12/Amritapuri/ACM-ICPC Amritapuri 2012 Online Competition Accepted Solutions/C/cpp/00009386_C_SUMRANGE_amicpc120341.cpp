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
# define MAXN 1100
# define MAXVAL 1000100

int MaxVal;
int tree[MAXVAL];
int A[MAXN];
int n;
int L,H;

//STANDARD BIT CODE
int read(int idx)
{
  int sum = 0;
  while (idx > 0){
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

void update(int idx ,int val)
{
  while (idx <= MaxVal){
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

void calc()
{
  int j,k,i,lo,hi;
  int Ans  = 0;
  MaxVal = 1000000;
  for(j = 0; j < n; j++)
    {
      for(k = j + 1; k < n; k++)
	{
	  lo = L - A[j] - A[k];
	  hi = H - A[j] - A[k];
	  if(lo < 1)
	    lo = 1;
	  if(hi < 1)
	    continue;

	  Ans = Ans + read(hi);
	  if(lo > 1);
	  Ans = Ans - read(lo - 1);
	}
      update(A[j], 1);
    }
  printf("%d\n", Ans);
}

int main()
{
  int t,i;
  scanf("%d", &t);
  while(t--)
    {
      scanf("%d %d %d", &n, &L, &H);
      memset(tree, 0, sizeof(tree));
      for(i = 0; i < n; i++)
	{
	  scanf("%d", &A[i]);
	}
      calc();
	     
    }

  return 0;
}
