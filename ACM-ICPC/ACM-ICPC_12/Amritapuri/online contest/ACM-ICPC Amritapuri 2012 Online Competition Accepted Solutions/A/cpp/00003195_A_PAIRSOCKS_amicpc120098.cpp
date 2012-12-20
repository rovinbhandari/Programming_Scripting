#include <iostream>
#include <cstdio>
#include <vector>
#include<cstring>
using namespace std;
int main()
{
  int i,j,t;
  char str[100];
  scanf("%d",&t);
  for(i=0;i<t;i++)
  {
    scanf("%s",str);
    int r=0,g=0,b=0,w=0;
    for(j=0;j<strlen(str);j++)
    {
      if(str[j]=='R')
	r++;
      else if(str[j]=='G')
	g++;
      else if(str[j]=='W')
	w++;
      else if(str[j]=='B')
	b++;
    }
    if(r%2==0 && g%2==0 && w%2==0 && b%2==0)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
  }
  return 0;
}


