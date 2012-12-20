#include <string.h>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<cstdio>
#include<cstring>
#include<vector>
#include<complex>
#define _USE_MATH_DEFINES//M_PI

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define pf(n)                       printf("%lf\n",n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define p(n)                       printf("%d\n",n)
#define pl(n)                      printf("%lld\n",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(i=a;i<b;i++)
#define foralle(i,a,b)               for(i=a;i<=b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
//#include <conio.h>

using namespace std;

int main(int argc, char *argv[])
{
    int t,i,n,m,cnt,j;
    s(t);
    while(t--)
     {
              cnt=0;
              s(n),s(m);
              long long int l[n],dd;
              long long int a[m],b[m],c[m];
              long long int diag,max=-1,x;
             for(i=0;i<n;i++)
              {
                  sl(l[i]);           
              }
            // puts("x");
             for(j=0;j<m;j++)
              {
                   sl(a[j]),sl(b[j]),sl(c[j]); 
                   diag=a[j]*a[j]+ b[j]*b[j]+   c[j]*c[j];
                   if(diag>max)
                    {
                           max=diag;    
                    }     
              }
             //pl(max);
            // dd=sqrt(max);
             for(i=0;i<n;i++)
              {
                             x=l[i]*l[i];
                             //pl(x);
                   if((max/(l[i]*l[i]))>=1)
                              {
                                                  cnt++;
                                                 // pf(l[i]);
                              }
                   
              }
             p(cnt);
     }
    //getch();
    return 0;
}


