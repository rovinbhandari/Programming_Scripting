#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int t, countR, countG, countB, countW;
    char input[100];
    scanf("%d", &t);
    while (t--) {
        scanf("%s", &input);
        int len = strlen(input);
        countB = countG = countR = countW = 0;
        for (int i=0; i < len; i++) {
            if (input[i] == 'R') {
                countR++;
            }
            if (input[i] == 'G') {
                countG++;
            }
            if (input[i] == 'B') {
                countB++;
            }
            if (input[i] == 'W') {
                countW++;
            }
        }
        if (countR % 2 == 0 && countB % 2 == 0 && countG % 2 == 0 && countW % 2 == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
