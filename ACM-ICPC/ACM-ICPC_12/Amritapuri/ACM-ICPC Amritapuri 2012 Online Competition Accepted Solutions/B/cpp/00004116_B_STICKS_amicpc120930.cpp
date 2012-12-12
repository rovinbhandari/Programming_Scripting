#include <iostream>
#include <cmath>

using namespace std;

int main()
{
        int t, n, m;
        cin >> t;
        long long int pp, a, b, c, s, cnt;
        long int l[50001];
        while (t--) {
                pp = 0;
                cin >> n >> m;
                for (int i = 0; i < n; i++) {
                        cin >> l[i];
                }
                for (int i = 0; i < m; i++) {
                        cin >> a >> b >> c;
                        s = sqrt(a*a + b*b + c*c);
                        if (s > pp) {
                                pp = s;
                        }
                }
                cnt = 0;
                for (int i = 0; i < n; i++ ){
                        if (l[i] <= pp) {
                                cnt++;
                        }
                }
                cout << cnt << endl;
        }

        return 0;
}
