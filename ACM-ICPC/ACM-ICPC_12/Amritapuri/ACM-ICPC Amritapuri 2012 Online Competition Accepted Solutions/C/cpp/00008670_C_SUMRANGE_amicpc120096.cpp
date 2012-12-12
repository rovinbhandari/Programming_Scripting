
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <queue>
#include <cassert>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define in(n) scanf("%d",&n)
#define inl(n) scanf("%lld",&n)
#define out(n) printf("%d ",n)
#define outln(n) printf("%d\n",n)
#define outl(n) printf("%lld ",n)
#define outlln(n) printf("%lld\n",n)
#define LL long long 
#define pb push_back
#define f first
#define s second

using namespace std;
int A[1024], h[1000010], h1[1000010];
int main()
{
    int X;
    in(X);
    while(X--)
    {
        memset(h, 0, sizeof(h));
        memset(h1, 0, sizeof(h1));
        int N, L, H;
        in(N);in(L);in(H);
        rep(i, 0, N) 
        {
            in(A[i]);
            if( A[i] <= H) h1[A[i]]++;
        }
        rep(i, 0, N) rep(j, 0, N) 
        {
            int tot = A[i] + A[j];
            if(tot <= H) 
            {
                h[tot]++;
            }
        }
        rep(i, 1, H + 1) h1[i] += h1[i-1], h[i] += h[i-1];
        int res = 0;
        rep(i, 0, N) 
        {
            if( A[i] <= H)  res += h[H - A[i]];
            if( L - 1 - A[i] >= 0) res -= h[L - 1 - A[i]];
          //  {
            //    res += h[H - A[i]] - h[L - 1 -A[i]];
            //}
        }
       // printf("re si s%d\n", res);
      /*  int rt = 0, bc =0;
        rep(i, 0, N) rep(j, 0, N) rep(k, 0, N)
        {
            int tot = A[i] + A[j] + A[k];
            if( (i==j) || (j==k) || (i==k) ) if (!( (i==j) && (j==k))) 
            if(tot >= L && tot <= H)

                bc++;
            if(tot >= L && tot <= H) rt++;
        }*/
  //      printf("rt is %d bc %d\n", rt, bc);
        int yu = 0;
        rep(i, 0, N) 

        {
            if(3 * A[i] >= L && 3*A[i] <= H) yu++,res--;
        }
        int tmp = 0;
        rep(i, 0, N) 
        {
            int a = 2* A[i];
            if( a <= H) tmp += h1[H - a];
            if( L -1 -a >=0 ) tmp -= h1[L-1-a];
           // {
             //   tmp  += (h1[H - a] - h1[L - 1 - a]);
           // }
        }
        tmp -= yu;
//        printf("tmp is %d\n", tmp);
       /* int pt=0;
            rep(i, 0, N)rep(j, i+1, N)rep(k, j+1, N) 
        {
            int tot = A[i] + A[j] + A[k];
            if(tot >= L && tot <= H) pt++;

        }*/
        printf("%d\n",(res - 3*tmp)/6);
        //outln((res - 3*tmp) / 6);
        
    }

    return 0;
}
