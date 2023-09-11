/* 
 * File:   main.c
 * Author: Adz
 *
 * Created on 4 November, 2012, 9:52 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int t;
    int i,g,b,w,r;
    char c[100];
    scanf("%d",&t);
    while (t>0){
        g=0,b=0,w=0,r=0;
        i=0;
            scanf("%s",c);
            
            while(c[i]!='\0'){
                if (c[i]=='G'){
                    if (g==1) g=0;
                    else g=1;
                }
                if (c[i]=='W'){
                    if (w==1) w=0;
                    else w=1;
                }
                if (c[i]=='R'){
                    if (r==1) r=0;
                    else r=1;
                }
                if (c[i]=='B'){
                    if (b==1) b=0;
                    else b=1;
                }
                i++;
            }
            
        
        if (g==0 && w==0 && r==0 && b==0){
                printf("YES\n");
            }
            else printf("NO\n");
        t--;
        }

    return (EXIT_SUCCESS);
}

