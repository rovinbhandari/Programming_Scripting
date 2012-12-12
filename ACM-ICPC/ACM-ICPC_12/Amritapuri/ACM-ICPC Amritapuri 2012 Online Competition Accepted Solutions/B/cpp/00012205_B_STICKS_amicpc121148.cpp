#include<iostream>
#include <cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include <vector>
using namespace std;


int main() {
    int T;
    scanf("%d",&T);
    while(T-- > 0) {
        int N,M;
        scanf("%d%d",&N,&M);
        vector<long int> L(N),A(M),B(M),C(M),D(M);
        for(int i=0;i<N;i++) {
            scanf("%ld",&L[i]);
        }
        int max=0;
        int counter=0;
        for(int i=0;i< M;i++) {
            scanf("%ld%ld%ld",&A[i],&B[i],&C[i]);
            long int temp = A[i] * A[i] + B[i] * B[i] + C[i] * C[i];
            D[i] = (long int)sqrt(temp);
            //cout << D[i];
            if (D[i] > max){
                max = D[i];
            }
        }
        //printf("\n");

        for(int i=0;i<N;i++){
            if (L[i] <= max){
                counter++;
            }
        }
        printf("%d\n",counter);
    }
    return 0;
}
