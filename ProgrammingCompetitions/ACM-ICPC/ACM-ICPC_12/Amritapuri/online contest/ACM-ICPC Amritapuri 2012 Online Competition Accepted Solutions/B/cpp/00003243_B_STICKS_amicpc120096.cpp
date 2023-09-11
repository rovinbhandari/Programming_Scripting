
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
long long L[50010];
int main()
{
    int X;
    in(X);
    while(X--)
    {
        int N, M;
        in(N);in(M);
        rep(i, 0, N) inl(L[i]);
        long long a, b, c, fans = -1;
        rep(i, 0, M)
        {
            inl(a);inl(b);inl(c);
            //int T[3] = {a, b, c};
            long long hp = a*a + b*b + c*c;
            fans = max(fans, hp);
        }
        int ans = 0;
        rep(i, 0, N)if(L[i] * L[i] <= fans) ans++;
        outln(ans);
    }
    return 0;
}
