/** author -- Ayush Sharma **/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<cassert>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define min3(a,b,c) (a<b?(a<c?a:c):(b<c?b:c))
#define max3(a,b,c) (a>b?(a>c?a:c):(b>c?b:c))
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define MAX 100001
#define infi 100000
using namespace std;
typedef long long LL;
int main(){
    int test;
    scanf("%d",&test);
    int a[1001];
    while(test--){
        int N,L,H;
        scanf("%d%d%d",&N,&L,&H);
        FOR(i,0,N){
            scanf("%d",&a[i]);
        }
        sort(a,a+N);
        int cnt=0;
        FOR(i,0,N-2){
            if(a[i]>H)break;
            FOR(j,i+1,N-1){
                if(a[i]+a[j]>H)break;
                FOR(k,j+1,N){
                    if((a[i]+a[j]+a[k]>=L) &&(a[i]+a[j]+a[k]<=H))cnt++;
                    else if(a[i]+a[j]+a[k]>H)break;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
