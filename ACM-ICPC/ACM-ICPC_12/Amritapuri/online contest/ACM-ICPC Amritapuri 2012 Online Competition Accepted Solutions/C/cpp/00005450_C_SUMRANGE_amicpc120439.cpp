#include<iostream>
using namespace std;
#include<algorithm>
#include<set>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<cstdio>
#include<map>

typedef long long lli;
typedef long li;

#define fi(i,a,b,d) for(i=a;i<=b;i+=d)
#define fir(i,a,b,d) for(i=a;i>=b;i-=d)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

#define vi vector<int>
#define all(v) v.begin(), v.end()

#define mp make_pair
#define pushb push_back
#define popb pop_back
#define pushf push_front
#define popf pop_front


#define inpi(i) scanf("%d", &i)
#define inplli(i) scanf("%lld", &i)
#define inpc(ch) scanf("%c", &ch)
#define printi(i) printf("%d\n", i)
#define printlli(i) printf("%lld\n", i)
#define printc(ch) printf("%c\n", ch)
#define inpfl(fl) scanf("%f", &fl)
#define printfl(fl) printf("%f", fl)


lli arr[1001], ans;

lli bin(lli l, lli r, lli val, int type)
{
     lli lo, hi, mid,ret=-1;
     
     lo=l;
     hi=r;
     
     mid = (lo+hi)/2;
     
     
     if(type == 1 && arr[l]>val) return l;
     if(type == 1 && arr[r]<val) return -1;
     if(type == 2 && arr[r]<val) return r;
     if(type == 2 && arr[l]>val) return -1;
     
     while(lo<=hi)
     {
         mid = (lo+hi)/2;
         if(arr[mid]==val)
         {
                          ret = mid;
                          if(type==1) hi=mid-1;
                          else lo=mid+1;
         }
         
         if(arr[mid]<val)
         {
                         lo = mid+1;
                         if(type==2) ret=mid;
                         
         }
         else
         {
             hi = mid-1;
             if(type==1) ret = mid;
         }
     }
     
     return ret;
}

/*
void fun(lli l, lli r, lli lo, lli hi)
{
     lli sum;
     sum = arr[i] + arr[j] + arr[k];
     /*
     if(sum>=lo && sum<=hi)
     {
      ans++;
      fun(l,r-1,lo,hi);
      fun(l+1,r,lo,hi);
     }
     
     else if(sum<lo)
     fun(l+1,r,lo,hi);
     else
     fun(l,r-1,lo,hi);
     ///
     
     sum = lo-arr[i];
}
*/

int main()
{
    lli t, lo, hi, n, i,j,k, ans;
    
    
    
    cin>>t;
    
    while(t--)
    {
              cin>>n>>lo>>hi;
              
              fi(i,0,n-1,1)
              cin>>arr[i];
              ans=0;
              
              sort(arr, arr+n);
              
              fi(i,0,n-3,1)
              {
                           //fun(i+1, n-1, lo, hi);
                           
                           lli temp, t2, t1;
                           fi(j,i+1,n-2,1)
                           { temp = lo-(arr[i]+arr[j]);
                             t1 = bin(j+1, n-1, temp, 1);
                             
                             temp = hi-(arr[i]+arr[j]);
                             t2 = bin(j+1, n-1, temp, 2);
                             
                             if(t1==-1 || t2==-1)
                             {}
                             else
                             {
                                 ans += t2-t1+1;
                             }
                           }
              }
              
              cout<<ans<<'\n';
    }
    
    return 0;
}
