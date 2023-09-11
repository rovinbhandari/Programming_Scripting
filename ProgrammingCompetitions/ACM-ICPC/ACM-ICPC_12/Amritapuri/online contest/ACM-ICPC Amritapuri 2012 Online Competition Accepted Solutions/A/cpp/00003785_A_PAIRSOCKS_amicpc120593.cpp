#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int arr[256];
int main() {
    int T,rc,gc,bc,wc;
    char input[100];
    scanf("%d",&T);
    int len,i;
    while(T--) {
        scanf("%s",input);
        len = strlen(input);
        if (len%2!=0)
            printf("NO\n");
        else
        {
        rc=gc=bc=wc=0;
        for(i=0;i<len;i++) {
            if(input[i]=='R')
                rc++;
            else if(input[i]=='W')
                wc++;
            else if(input[i]=='G')
                gc++;
            else if(input[i]='B')
                bc++;
        }
        
        if(rc%2==0 && wc%2==0 && gc%2==0 && bc%2==0)
            printf("YES\n");
        else
            printf("NO\n");
        
        }
    }
    
    
    return 0;
}
