#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> lst;
vector<int> lst2;

int main() {
    int t;
    int n,l,h;
    int i,j;
    int a[1009];
    long long ans;
    scanf("%d",&t);
    int temp;
    while(t--) {
        scanf("%d%d%d", &n,&l,&h);
        for(i=0; i<n; ++i) {
            scanf("%d", &a[i]);
        }
        lst.clear();
        lst2.clear();
        for(i=0; i<n; ++i) {
            for(j=i+1; j<n; ++j) {
                temp = a[i]+a[j];
                if(temp > h) {
                    continue;
                }
                lst.push_back(temp);
            }
        }
        sort(lst.begin(), lst.end());
        for(i=0; i<n; ++i) {
            temp = a[i] + a[i];
            if(temp > h) continue;
            lst2.push_back(temp);
        }

        sort(lst2.begin(), lst2.end());
        ans = 0;
        for(i=0; i<n; ++i) {
            temp =  upper_bound(lst.begin(), lst.end(), h-a[i]) - lower_bound(lst.begin(), lst.end(), l-a[i]);
            ans += temp;
        }
        for(i=0; i<n; ++i) {
            temp =  upper_bound(lst2.begin(), lst2.end(), h-a[i]) - lower_bound(lst2.begin(), lst2.end(), l-a[i]);
            ans -= temp;
        }
        for(i=0; i<n; ++i) {
            temp = a[i] + a[i] + a[i];
            if(temp <= h && temp >= l) {
                ans ++;
            }
        }
        ans = ans/3;
        printf("%Ld\n", ans);
    }
    return 0;
}
