#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define MAX 500000
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int N,M;
        scanf("%d %d",&N,&M);
        double A[N];
        for(int i=0;i<N;i++){
            scanf("%lf",&A[i]);
        }
        double max=0;
        for(int i=0;i<M;i++){
            double l,w,h;
            scanf("%lf %lf %lf",&l,&w,&h);
            double a=(l*l + w*w +h*h);
            a=sqrt(a);
            if(a>max)
                max=a;
        }
        long long suma=0;
        for(int i=0;i<N;i++)
            if(A[i]<=max)
                suma+=1;
        printf("%lld\n",suma);

    }
	return 0;
}
