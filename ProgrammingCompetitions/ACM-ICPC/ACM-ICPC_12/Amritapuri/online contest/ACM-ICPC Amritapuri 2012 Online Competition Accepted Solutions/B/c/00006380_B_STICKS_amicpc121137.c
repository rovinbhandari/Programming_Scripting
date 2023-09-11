/* 
 * File:   main.c
 * Author: surendra
 *
 * Created on November 4, 2012, 9:43 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
    long long int T,N,M,B,k=0;
     int i;
    long long int* j;
    long long int max;
    long long int size;
    scanf("%lld",&T);
    j=(long long int*)malloc(T*sizeof(long long int));
    while(T>0)
    {
        long long int* length;
        long long int* bx;
        long long int* by;
        long long int* bz;
    
        T=T-1;
        max=0;
        size=0;
        scanf("%lld%lld",&N,&B);
        length=(long long int*)malloc(N*sizeof(long long int));
        for(i=0;i<N;i++)
        {
         scanf("%lld",&length[i]);
         length[i]=length[i]*length[i];
        }
        bx=(long long int*)malloc(B*sizeof(long long int));
        by=(long long int*)malloc(B*sizeof(long long int));
        bz=(long long int*)malloc(B*sizeof(long long int));
        
        for(i=0;i<B;i++)
        {
            scanf("%lld%lld%lld",&bx[i],&by[i],&bz[i]);
            size=(bx[i]*bx[i]+by[i]*by[i]+bz[i]*bz[i]);
            if(max<size)
            {
                max=size;
            }
        }
        B=0;
        for(i=0;i<N;i++)
        {
            if(length[i]<=max)
                B++;
        }
        j[k]=B;
        k++;
        free(bx);
        free(by);
        free(bz);
        free(length);
    }

    for(i=0;i<k;i++)
        printf("%lld\n",j[i]);
    return (EXIT_SUCCESS);
}

