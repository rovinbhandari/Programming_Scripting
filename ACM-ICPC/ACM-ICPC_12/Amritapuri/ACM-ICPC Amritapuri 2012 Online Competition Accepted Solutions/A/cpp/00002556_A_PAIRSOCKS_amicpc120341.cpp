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
# define MAXN 100

char S[MAXN];
int red,green,blue,white;
void calc()
{
  int i;
  red = blue = green = white = 0;
  for(i = 0; S[i]; i++)
    {
      if(S[i] == 'R')
	red++;
      else if(S[i] == 'W')
	white++;
      else if(S[i] == 'B')
	blue++;
      else green++;
    }
  if(red % 2 == 0 && green % 2 == 0 && blue % 2 == 0 && white % 2 == 0)
    printf("YES\n");
  else printf("NO\n");
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    {
      scanf("%s", S);
      calc();
    }

  return 0;
}
