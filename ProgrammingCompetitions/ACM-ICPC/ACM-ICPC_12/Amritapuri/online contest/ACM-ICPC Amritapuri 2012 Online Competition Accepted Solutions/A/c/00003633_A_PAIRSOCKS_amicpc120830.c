#include <stdio.h>

int main(){
    int cases, i, j, red, blue, green, white;
    char sock[1000][51]={0};
    
    scanf("%d", &cases);
    
    for(i=0; i<cases; i++){
        scanf("%s", sock[i]);
    }
    
    for(i=0; i<cases; i++){
        red=green=blue=white=0;
        for(j=0; sock[i][j]!=0&&j<50; j++){
            switch(sock[i][j]){
                case 'R': red++;break;
                case 'G': green++;break;
                case 'B': blue++;break;
                case 'W': white++;break;
            }
        }
        if(!(red&0x1)&&!(green&0x1)&&!(blue&0x1)&&!(white&0x1))printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
