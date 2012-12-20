#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define s(T) scanf("%d", &T)
#define sl(T) scanf("%lld", &T)
#define fill(a, val) memset(a, val, sizeof(a))

int main()
{
    int t,i, cnt    ;
    int n,m;

    unsigned long L[100002];
    unsigned long a, b, c, l;

    unsigned long max_l;

    scanf("%d", &t);

    while(t--)
    {
        s(n);
        s(m);
        cnt =0; max_l=0;
        unsigned long temp;
        for(i=0;i<n;i++)
        {
            scanf("%lu", &temp);
            L[i]=temp*temp;
        }

        for(i=0;i<m;i++)
        {
            scanf("%lu", &a);
            scanf("%lu", &b);
            scanf("%lu", &c);

            l = pow(a,2) + pow(b,2) + pow(c, 2);
            if (max_l < l) max_l = l;
        }
        cnt = 0;
        for (i=0; i < n; i++) {
            if (max_l >= L[i]) cnt++;
        }
        printf("%d\n", cnt);
    }


    return 0;
}
