#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    long long int T, N, M, max, x,y,z,i;
    scanf("%lld", &T);
    while(T--){
        long long int sticks[50001] = {0};
        scanf("%lld%lld", &N, &M);
        i=0;
        long long int K=N;
        while(N--){
            scanf("%lld",&sticks[i]);
            sticks[i]=sticks[i]*sticks[i];
            i++;
        }
        max = 0;
        while(M--){
            scanf("%lld%lld%lld", &x, &y, &z);
            long long int temp = x*x + y*y + z*z;
            if (temp > max )
                max = temp;
        }
        vector<long long int> v(sticks,sticks+K);
        vector<long long int>::iterator low,up;
        sort (v.begin(), v.end());
        low=lower_bound (v.begin(), v.end(), max);
        up= upper_bound (v.begin(), v.end(), max);
        printf("%d\n", int(up- v.begin()));
    }
    return 0;
}
