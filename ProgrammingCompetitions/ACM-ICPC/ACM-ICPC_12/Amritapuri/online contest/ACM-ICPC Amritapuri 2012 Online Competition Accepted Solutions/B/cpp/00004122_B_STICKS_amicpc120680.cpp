// Authors : The_Iterators
#include <cstdio>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define MAX 50002
#define MAXD 50002
using namespace std;
long long L[MAX];
long long A[MAXD];
long long B[MAXD];
long long C[MAXD];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int N,M;
        scanf("%d %d",&N,&M);
        for(int i=0;i<N;i++)
            scanf("%lld",&L[i]);
        long long maxD = 0;
        for(int i=0;i<M;i++) {
            scanf("%lld %lld %lld",&A[i],&B[i],&C[i]);
            maxD = max(A[i]*A[i]+B[i]*B[i]+C[i]*C[i], maxD);
        }
        int cnt = 0;
        for(int i=0;i<N;i++) {
            if(L[i]*L[i] <= maxD) {
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
	return 0;
}
