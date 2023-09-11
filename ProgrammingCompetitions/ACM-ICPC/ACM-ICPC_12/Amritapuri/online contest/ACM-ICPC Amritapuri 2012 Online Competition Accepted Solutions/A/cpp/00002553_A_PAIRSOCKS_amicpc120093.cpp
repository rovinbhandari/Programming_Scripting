#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int main() {
    int N;
    scanf("%d",&N);
    int nums[1000];
    int i;
    while(N--) {
        memset(nums, 0, sizeof(nums));
        string a;
        cin>>a;
        for(i=0; i<a.size(); ++i) {
            nums[a[i]-'A'] ++;
        }

        if(nums['R'-'A']%2 == 0 && nums['G'-'A']%2 == 0 && nums['B'-'A']%2 == 0 && nums['W'-'A']%2 == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

    }
    return 0;

}
