#include <stdio.h>
#include <stdlib.h>

int main() {
    int R = 0 , G = 0, B = 0, W = 0;
    int i=0;
    scanf("%d",&i);
    while(i-->0) {
        R = 0, G = 0, B = 0, W = 0;
        char *c = malloc(sizeof(char *)*100);
        scanf("%s",c);
        int ind =0;
        while(c[ind] != '\0') {
            if (c[ind] == 'R') { R++; }
            else if (c[ind] == 'G') { G++; }
            else if (c[ind] == 'B') { B++; }
            else if (c[ind] == 'W') { W++; }
            ind++;
        }
        if (R%2 == 0 && G%2 == 0 && B%2 == 0 && W%2 == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
return 0;
}
