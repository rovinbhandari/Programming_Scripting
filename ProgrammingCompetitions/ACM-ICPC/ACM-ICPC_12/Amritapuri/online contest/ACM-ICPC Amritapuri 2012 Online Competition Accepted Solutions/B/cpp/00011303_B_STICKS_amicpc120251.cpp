#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

int main()
{
        int test, n, m;
        
        long long int k, aA, bB, cC, prad, cont;
        long int l[50001];

	scanf("%d", &test);
        while (test--) {
                k = 0;
                scanf("%d %d", &n, &m);
                for (int i = 0; i < n; i++) {
                        cin >> l[i];
                }
                for (int i = 0; i < m; i++) {
                        scanf("%lld %lld %lld", &aA, &bB, &cC);
                        prad = sqrt(aA*aA + bB*bB + cC*cC);
                        if (prad > k) {
                                k = prad;
                        }
                }
                cont = 0;
                for (int i = 0; i < n; i++ ){
                        if (l[i] <= k) {
                                cont++;
                        }
                }
                cout << cont << endl;
        }

        return 0;
}
