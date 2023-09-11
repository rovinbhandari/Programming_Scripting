#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<iterator>
#include<string>
#include<sstream>
using namespace std;

int N,L,H,ar[2001];
long long ans;
int hash[1500000],sum[1500000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&N,&L,&H);
        for(int i=0;i<N;i++) scanf("%d",&ar[i]);
        sort(ar,ar+N);
        ans = 0;
        for(int i=0;i<N;i++){
            int j = i+1,k = N-1;
            while(j < k){
                if(ar[j]+ar[k] +ar[i] > H ) --k;
                else{
                    ans += k-j;
                    ++j;
                }
            }
        }
        for(int i=0;i<N;i++){
            int j = i+1,k = N-1;
            while(j < k){
                if(ar[j]+ar[k] +ar[i] > L-1 ) --k;
                else{
                    ans -= k-j;
                    ++j;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
