#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
using namespace std;

#define si(T) scanf("%d", &T)
#define sil(T) scanf("%lld", &T)
#define FOR(i,a,b) for(i=a;i<=b;i++)
const int MOD = 1000000007;
 /* Fast power function*/
long long pow(long long a, int exp)
{
	if(exp == 0) return 1;
	if(exp & 1)
		return (a*pow((a*a)%MOD, exp>>1))%MOD;
	else
		return pow((a*a)%MOD, exp>>1);
}

int main()
{   //freopen("art.in","r", stdin);
   //freopen ("art.out","w",stdout);
   int i,t,r,w,g,b,len;
   char c[51];
   si(t);
    while(t--)
 {  r=0,w=0,b=0,g=0;
     scanf("%s",&c);
     len=strlen(c);
     for(i=0;i<len;i++)
     {
         if(c[i]=='R')
         r++;
         else if(c[i]=='G')
         g++;
         else if(c[i]=='W')
         w++;
         else if(c[i]=='B')
         b++;
     }
     if(r%2==0 && b%2==0 && w%2==0 && g%2==0)
     printf("YES\n");
     else
     printf("NO\n");
     /*
    si(n);
   int a[n+1];
    FOR(i,1,n) { si(a[i]); }
    */
      /*Main logic here*/
  }

 //fclose(stdin);
 // fclose(stdout);
 return 0;
}
