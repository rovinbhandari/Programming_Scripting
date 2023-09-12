#include <cstdio>
#include <algorithm>
using namespace std;

long long max1(long long a, long long b) {
    if(a>b) return a;
    return b;
}

int main() {
    int t;
    long long int mx1,mx;
    int N,M;
    long long a,b,c;
    int i;
    long long int s[100000];
    scanf("%d",&t);
    while(t--) {
        mx = -1;
        scanf("%d%d",&N,&M);
        for(i=0; i<N; ++i) {
            scanf("%Ld", &s[i]);
        }
        for(i=0; i<M; ++i) {
            scanf("%Ld%Ld%Ld", &a,&b,&c);
            mx1 = a*a+b*b+c*c;
            mx = max1(mx1,mx);
        }

        int ans = 0;
        for(i=0; i<N; ++i) {
            if(s[i]*1LL*s[i] <= mx) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
