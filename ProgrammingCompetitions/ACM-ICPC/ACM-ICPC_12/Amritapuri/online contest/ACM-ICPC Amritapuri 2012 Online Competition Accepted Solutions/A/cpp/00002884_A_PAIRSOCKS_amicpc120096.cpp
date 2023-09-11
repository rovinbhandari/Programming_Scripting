
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

map<char, int> s;

int main()
{
    int X;
    in(X);
    while(X--) {
        s.clear();
        string ss;
        cin>>ss;
        for(int i=0;i<ss.length();i++) {
            s[ss[i]]++;
        }
        if(s['R']%2==0 && s['G']%2==0 && s['B']%2==0 && s['W']%2==0) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }

    return 0;
}
