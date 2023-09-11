#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    long long int n, m, mx, i, j, t, x, y, z, vol, sq;
    long long int l[100005];
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> m;
        for (i = 0; i < n; i++)
        {
            cin >> l[i];
        }
        mx = 0;
        for (i = 0; i < m; i++)
        {
            cin >> x >> y >> z;
            vol = x * x + y * y + z * z;
            sq = sqrt(vol);
            mx = max(sq, mx);
        }
        long long int cnt = 0;
        for (i = 0; i < n; i++)
        {
            if (l[i] <= mx)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
