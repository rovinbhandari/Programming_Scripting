#include <cstring>
#include<stdio.h>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
#define for(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define mod 1000000007
#define MAXN 1000010
#define get getchar//_unlocked
inline int inp()
{
    int n=0,s=1;
    char p=get();
    if(p=='-')
    s=-1;
    while((p<'0'||p>'9')&&p!=EOF)
    p=get();
    while(p>='0'&&p<='9')
    {
    n = (n<< 3) + (n<< 1) + (p - '0');
    p=get();
    };
    return n*s;
}
int a[27];
int main()
{
    int i,n,j,k,l,m,t,ans;
    t=inp();
    while(t--)
    {

      char c=get();
      while(c!='\n')
      {
          a[c-'A']++;
          c=get();
      }
      int flag=0;
       for(i,0,26)
       {
           if(a[i]%2)
           {printf("NO\n");
           flag=1;
           break;}
       }
       if(flag==0)
       printf("YES\n");
       memset(a,0,sizeof(a));
    }
    return 0;
}

