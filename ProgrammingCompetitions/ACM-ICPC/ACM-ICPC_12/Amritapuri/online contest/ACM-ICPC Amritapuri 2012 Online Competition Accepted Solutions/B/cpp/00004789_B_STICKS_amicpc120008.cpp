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
#define PB push_back
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
   for(int j=2;j*j<=k;j++)
   {
     p=1;
     while(k%j==0)
     {
       p=p*j+1;
       k/=j;
     } 
     pro=pro*p;
   }
   if(k>1)
     pro*=1+k;

   return pro;
}
struct abc{
       int x;
       int y;
       }obj[65];
bool st_sorter(abc const& lhs, abc const& rhs) {      //sort(obj,obj+n,st_sorter);
        return lhs.x < rhs.x;
    }  
/*ll fun(     )
{
            
            
            
            
            

return
}*/
using namespace std;

int main()
{

    ll i,j,min,max,t,x[100005],n,m;
    scanf("%lld",&t);
    while(t--)   //while(scanf("%d",&n)!=EOF)
    {  ll count=0,max=0;
      cin>>n>>m;
      ll a[n],l[m],b[m],h[m];
      for(i=0;i<n;i++){
	  				   cin>>a[i];
	  				   a[i]=a[i]*a[i];
					   }
	   for(i=0;i<m;i++){
	   					cin>>l[i]>>b[i]>>h[i];
						x[i]=(l[i]*l[i] + b[i]*b[i] + h[i]*h[i]);
						if(x[i]>max)
						max=x[i];
						} //cout<<max<<endl;
						
      for(i=0;i<n;i++){
	  				   if(a[i]<=max)
	  				   count++;
					   }
	   cout<<count<<endl;
	   
	  				   
     

    }
//system("pause");
return 0;
}
