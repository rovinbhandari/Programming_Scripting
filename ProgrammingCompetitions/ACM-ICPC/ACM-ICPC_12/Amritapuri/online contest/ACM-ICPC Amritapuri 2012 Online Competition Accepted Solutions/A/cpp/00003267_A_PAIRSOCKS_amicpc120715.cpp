#include <cstdio>
#include <cstring>

int main () {
    int t, n, m, i, l, count[5] = {0,0,0,0,0};
    char socks[50], f=0;
    scanf("%d", &t);

    while(t--) {
        scanf("%s", &socks);
        f=0;
        count[0]=0;
        count[1]=0;
        count[2]=0;
        count[3]=0;
        l = strlen(socks);
        for (i=0; i < l; i++) {
            switch(socks[i]) {
                case 'R':
                    count[0]++;
                    break;
                case 'G':
                    count[1]++;
                    break;
                case 'B':
                    count[2]++;
                    break;
                case 'W':
                    count[3]++;
                    break;
            }
        }

        for (i = 0; i < 4; i++) {
            if (count[i] %2 != 0) {
                f=1;
                break;
            }
        }

        if (f) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
