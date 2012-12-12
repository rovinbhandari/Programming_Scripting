#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>

#define fr(i,a,b) for (int i = a; i <= b; i++)
#define tr(c,it) for (typeof(c.end()) it = c.begin(); it != c.end(); it++)
#define MAXN 1010

typedef long long int lli;

using namespace std;

int a[MAXN];

lli numPairs(int H, int n) {
  lli ans = 0;
  fr(i,1,n-2) {
    if (a[i] > H) break;
    int j = i+1, k = n;
    while (j < k) {
      if (a[i] + a[j] >= H) break;
      while(a[i] + a[j] + a[k] > H and k > j) k--;
      ans += k - j;
      j++;
    }
  }
  return ans;
}

int main() {
  int T, N, L, H;

  cin >> T;
  while (T--) {
    cin >> N >> L >> H;
    fr(i,1,N) cin >> a[i];
    
    sort(a+1, a+N+1);

    lli ans = numPairs(H, N) - numPairs(L-1, N);

    cout << ans << endl;
  }
  return 0;
}
