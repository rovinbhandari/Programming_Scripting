#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int L[50005];
int main()  {
    int T, N, M, i, ans;
    long long a, b, c, t, max;
    cin >> T;
    while(T--)  {
        cin >> N >> M;
        max = 0;
        for(i=0; i<N; i++)
            cin >> L[i];
        for(i=0; i<M; i++)  {
            cin >> a >> b >> c;
            t = sqrt(a*a + b*b + c*c);
            if(t > max) max = t;
        }
        ans = 0;
        for(i=0; i<N;i++)
            if(L[i] <= max) ans++;
        cout << ans << "\n";
    }
    return 0;
}
