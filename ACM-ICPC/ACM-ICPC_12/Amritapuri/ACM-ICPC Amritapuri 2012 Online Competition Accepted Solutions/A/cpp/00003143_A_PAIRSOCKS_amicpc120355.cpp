#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int casen,i;
    int red=0;
    int blue=0;
    int white=0;
    int green=0;
    char input[50];
    int len;
    scanf("%d\n", &casen);
    while(casen)
    {
        scanf("%s",input);
        len = strlen(input);
        if(len%2 != 0){
            printf("NO\n");
        }
        else{
            red=0;
            blue=0;
            white=0;
            green=0;
            for(i=0;i<len;i++){
                if(input[i] == 'R')
                    red++;
                else if(input[i] == 'G')
                    green++;
                else if(input[i] == 'B')
                    blue++;
                else
                    white++;
            }
            if(red%2 != 0 || green%2 != 0 || white%2 != 0 || blue%2 != 0){
                printf("NO\n");
            }
            else{
                printf("YES\n");
            }
        }
        casen--;
    }
    return 0;
}
