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

struct box{
    double x,y,z;
    double dig;
    box(){}
    box(int x1,int y1,int z1){
        x=x1;
        y=y1;
        z=z1;
        dig=sqrt(x*x+y*y+z*z);
    }
    bool operator>(box b2) const{
        return b2.dig<dig;
    }

    bool operator<(box b2) const{
        return b2.dig>dig;
    }

    bool operator==(box b2) const{
        return b2.dig==dig;
    }
};

int main(){
    int t,n,m;
    double lengths[50001];
    double x,y,z;
    box bx[50001];
    readint(t);
    while(t--){
        readint(n);
        readint(m);
        for(int i=0;i<n;i++){
            readd(lengths[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%lf%lf%lf",&x,&y,&z);
            bx[i]=box(x,y,z);
        }
        sort(lengths,lengths+n);
        sort(bx,bx+m);
        #ifdef db 
        cout<<bx[0].dig<<" "<<bx[1].dig<<endl;
        #endif

        int cnt=0,ptr1=0;
        for(int i=0;i<n;i++){
            if(ptr1==m) break;
            else if(lengths[i]<=bx[ptr1].dig){
                cnt++;
            }
            else{
                ptr1++;
                i--;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}