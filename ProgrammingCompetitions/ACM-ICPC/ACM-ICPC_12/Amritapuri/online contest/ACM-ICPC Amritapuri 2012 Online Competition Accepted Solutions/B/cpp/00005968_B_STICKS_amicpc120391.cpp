#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <deque>
#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p,0,sizeof(p))
#define LL long long int
#define ULL unsigned long long int
#define S(n)                    scanf("%d",&n)
#define Sl(n)                     scanf("%lld",&n)
#define Sf(n)                     scanf("%lf",&n)
#define Ss(n)                     scanf("%s",n)
#define rr 50001
using namespace std;
/* template <class T>
inline void r_f(T &p)
{
         char c;
         while ((c=getchar_unlocked()) < 48 | c > 57);
         p=c-48;
         while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
} */
LL l[rr],a[rr],b[rr],c[rr],w[rr],ct=0;
int main()
{
    LL t,i,j,k,n,m,q;
    #ifndef ONLINE_JUDGE
   // freopen("example.txt","r",stdin);
    #endif
    Sl(t);
    // r_f(t);
    while(t--)
    {
    	ct=0;
        Sl(n);
        Sl(m);
        
        
        for(i=0;i<n;i++)
        {
        	Sl(l[i]);
        	l[i]*=l[i];
        }
        for(i=0;i<m;i++)
        {
        	Sl(a[i]);
        	Sl(b[i]);
        	Sl(c[i]);
        	w[i]=pow(a[i],2)+pow(b[i],2)+pow(c[i],2);
        }
 
        q=*max_element(w,w+m);
        for(i=0;i<n;i++)
        {
        	if(l[i]<=q)
        	ct++;
        }
        cout<<ct<<endl;
    }
    return 0;
}
