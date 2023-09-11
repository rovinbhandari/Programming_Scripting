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
#define sl(n)                       scanf("%I64d",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define p(n)                       printf("%d\n",n)
#define pl(n)                      printf("%I64d\n",n)

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
    int t,i;
    char *p;
    char str[100];
    int cnt[100];
    s(t);
    while(t--)
     {
              int flag=1;
              memset(cnt,0,sizeof(cnt));
              ss(str);
              p=str;
              while(*p)
               {
                       cnt[*p]++;
                       
                       p++;
               }
              for(i=65;i<=92;i++)
               {
                     if(cnt[i]%2!=0)
                      {
                                    //printf("%c",i);
                                    flag=0;  
                                    break;
                      }          
               }
              if(flag==0)
               {
                          puts("NO");
                         
               }
              else
               {
                        puts("YES");
               }
     }
    //getch();
    return 0;
}


