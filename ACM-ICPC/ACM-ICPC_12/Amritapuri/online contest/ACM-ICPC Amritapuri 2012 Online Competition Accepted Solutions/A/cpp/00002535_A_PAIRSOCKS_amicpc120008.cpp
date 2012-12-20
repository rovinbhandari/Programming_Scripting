#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <utility>
#include <cctype>
#include <list>
#include <climits>
#include <signal.h>
#include <ctime>
#include <map>
#include <set>
#define SIZE 100000 
#define ll long long 
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
int a[SIZE];
template<typename T> T gcd(T a, T b) { return (b == 0) ? abs(a) : gcd(b, a % b); }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T mod(T a, T b) { return (a % b + b) % b; }
template<typename T> inline T sqr(T x) { return x * x; }
int maxx(int a[],int n)
{
    int max=0;
    FOR(i,0,n)
    {
              if(max<a[i])
              max=a[i];
    }
    return max;
}
int maxx3(int a,int b,int c)
{
    if(a>b&&a>c)
    return a;
    else if(b>c&&b>a)
    return b;
    else
    return c;
}
int maxx2(int a,int b)
{
    return a>b?a:b;
}
ll sumofdivisors(ll k)
{
   ll p,pro=1;
    for(int j=2;j*j<=k;j++){
        p=1;
        while(k%j==0){
            p=p*j+1;
            k/=j;
        }
        pro=pro*p;
    }
    if(k>1)
    pro*=1+k;

return pro;
}
ll gcd(ll x, ll y)
{
	    if (y == 0)
	        return x;
	    else
	        return gcd(y, x % y);
}

using namespace std; 
int i,j,t,n,x;
char c[100];
int main(){
    
    scanf("%d",&t);   //while(scanf("%d",&n)!=EOF)
    while(t--)
    { int cg=0,cb=0,cw=0,cr=0; 
            cin>>c;
            x=strlen(c);
            for(int i=0;i<x;i++){
                             if(c[i]=='R')
                             cr++;
                             else if(c[i]=='B')
                             cb++;
                             else if(c[i]=='W')
                             cw++;
                             else
                             cg++;
                             }
            if(cg%2 != 0 || cr%2!=0 || cw%2!=0 || cb%2!=0)
            cout<<"NO\n";
            else
            cout<<"YES\n";
            
            
    
    
    }
   // system("pause");
    return 0;
}
