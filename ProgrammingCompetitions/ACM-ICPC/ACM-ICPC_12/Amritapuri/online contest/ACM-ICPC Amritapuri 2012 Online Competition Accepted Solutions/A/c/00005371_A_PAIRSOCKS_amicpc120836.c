#include<stdio.h>

int main() {
    int T, i,j;
    scanf("%d", &T);
    char in[T][51];
    for(i=0; i<T; i++) {
        scanf("%s", in[i]);
    }
    int count_R, count_G, count_B, count_W;
    for(i=0; i<T; i++) {
        count_R = count_G = count_B = count_W = 0;
        for(j=0; j<50; j++) {
            if(in[i][j] == 0) break;
            if(in[i][j] == 'R') count_R++;
            if(in[i][j] == 'G') count_G++;
            if(in[i][j] == 'B') count_B++;
            if(in[i][j] == 'W') count_W++;
        }
        if((count_R%2) || (count_G%2) || (count_B%2) || (count_W%2))
            printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
