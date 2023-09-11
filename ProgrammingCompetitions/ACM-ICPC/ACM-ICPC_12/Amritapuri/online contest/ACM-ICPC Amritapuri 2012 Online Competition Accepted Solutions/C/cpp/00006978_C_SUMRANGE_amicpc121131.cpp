#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binsearch (vector<int> a, int ls, int le, int vs, int ve) {
    int ans = 0;
    while (ls <= le) {
        int mid = (ls + le) / 2;
        if (a[mid] < vs) {
            ls = mid + 1;
        } else if (a[mid] > ve) {
            le = mid - 1;
        } else {
            int i = mid;
            while ((i >= ls) && (a[i] >= vs)) {
                ans++;
                i--;
            }
            i = mid + 1;
            while ((i <= le) && (a[i] <= ve)) {
                i++;
                ans++;
            }
            break;
        }
    }
    return ans;
}

void test() {
    int N, L, H;
    cin >> N >> L >> H;
    vector<int> a;
    int in;
    for (int i = 0; i < N; i++) {
        cin >> in;
        a.push_back(in);
    }
    sort (a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int sum = a[i] + a[j];
            if (sum > H)
                continue;
            ans += binsearch(a, j + 1, N - 1, L - sum, H - sum);
        }
    }
    cout << ans << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        test();
    }
    return 0;
}
