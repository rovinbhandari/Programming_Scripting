#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <climits>
#include <cfloat>
#include <cassert>
#define readint(n)      scanf("%d",&n)
#define readull(n)      scanf("%llu",&n)
#define readll(n)       scanf("%lld",&n)
#define readf(n)        scanf("%f",&n)
#define readd(n)        scanf("%lf",&n)
#define init(mem)       memset(mem,0,sizeof(mem))
#define ll              long long int
#define ull             unsigned long long int
using namespace std;

int* vec;
int binSearch1(int val,int l,int u){
    #ifdef db
    cout<<"1 "<<val<<" "<<l<<" "<<u<<endl;
    #endif
    if(u-l<=1){
        if(vec[u]<=val){
            return u;
        }
        return l;
    }
    int m=(u+l)/2;
    if(vec[m]>val){
        return binSearch1(val,l,m);
    }
    else{
        return binSearch1(val,m,u);
    }
}

int binSearch2(int val,int l,int u){
    #ifdef db
    cout<<"2 "<<val<<" "<<l<<" "<<u<<endl;
    #endif
    if(u-l<=1){
        if(vec[l]>=val){
            return l;
        }
        return u;
    }
    int m=(u+l)/2;
    if(vec[m]>=val){
        return binSearch2(val,l,m);
    }
    else{
        return binSearch2(val,m,u);
    }
}

int main(){
    int t,n;
    ll l,h;
    int maxm,minm;
    int *mem=new int[10001];
    readint(t);
    while(t--){
        readint(n);
        readull(l);
        readull(h);

        for(int i=0;i<n;i++){
            readint(mem[i]);
        }

        sort(mem,mem+n);

        ll count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n-2;j++){
                #ifdef db
                cout<<"looking for "<<i<<" "<<j<<endl;
                #endif

                ll sm=mem[i]+mem[j];
                ll tolook1=h-sm;
                ll tolook2=l-sm;

                if(tolook1<mem[j+1] or tolook2>mem[n-1]){
                    continue;
                }

                #ifdef db
                cout<<endl<<tolook1<<" "<<tolook2<<endl;
                #endif

                if(tolook1>=mem[n-1]){
                    maxm=n-1;
                }
                else{
                    vec=mem;
                    maxm=binSearch1(tolook1,j+1,n-1);
                }

                if(tolook2<=mem[j+1]){
                    minm=j+1;
                }
                else{
                    vec=mem;
                    minm=binSearch2(tolook2,j+1,n-1);
                }

                #ifdef db
                cout<<"limits "<<maxm<<" "<<minm<<endl;
                #endif
                count+=(maxm-minm+1);
                #ifdef db
                cout<<(maxm-minm+1)<<"\n\n";
                #endif
            }
        }
        printf("%lld\n",count);
    }
    return 0;
}
/*

int main(){
    int n;
    cin>>n;
    int mem[n];
    for(int i=0;i<n;i++){
        cin>>mem[i];
    }
    vec=mem;
    while(1){
        int r;
        cin>>r;
        cout<<binSearch2(r,0,n-1)<<endl;
    }
    return 0;
}*/