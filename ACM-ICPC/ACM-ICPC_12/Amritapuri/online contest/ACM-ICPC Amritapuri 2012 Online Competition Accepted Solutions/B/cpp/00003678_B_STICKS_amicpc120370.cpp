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
//#define for(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define mod 1000000007
#define MAXN 1000010
#define get getchar//_unlocked
inline long long inp()
{
    long long n=0,s=1;
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
int main()
{
    long long i,n,j,k,m,t,ans,l,b,h,max;
    t=inp();
    while(t--)
    {
     n=inp();m=inp();
     long long a[n];
     for(i=0;i<n;i++)
     {
         a[i]=inp();
     }max=0;
     for(i=0;i<m;i++)
     {
         l=inp();b=inp();h=inp();
         j=(long long)sqrt((l*l+b*b+h*h));
         if(j>max)
         max=j;
     }long long c=0;
     for(i=0;i<n;i++)
     {
         if(a[i]<=max)
         c++;
     }
     printf("%lld\n",c);
    }
    return 0;
}

