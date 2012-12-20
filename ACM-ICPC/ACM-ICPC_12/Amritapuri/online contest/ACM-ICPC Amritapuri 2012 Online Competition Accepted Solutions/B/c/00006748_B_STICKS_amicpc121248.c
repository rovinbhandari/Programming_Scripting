/* 
 * File:   main.c
 * Author: Adz
 *
 * Created on 4 November, 2012, 10:40 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int t;
    scanf("%d",&t);
    unsigned int n,m,i;
    unsigned int a,b,c,cases;
    long int *j,max;
    while (t>0){
        max=0;
        cases=0;
        scanf("%d",&n);
        j = malloc (n*sizeof(long int));
        scanf("%d",&m);
        for (i=0;i<n;i++){
            scanf("%ld",&j[i]);
        }
        for (i=0;i<m;i++){
            scanf("%d",&a);
            scanf("%d",&b);
            scanf("%d",&c);
            if (((a*a)+(b*b)+(c*c))>max){
                max = (a*a)+(b*b)+(c*c);
            }
            
        }
        for (i=0;i<n;i++){
            if ((j[i]*j[i])<=max){
                cases++;
            }
        }
        printf("%d\n",cases);
     t--;   
    }

    return (EXIT_SUCCESS);
}

