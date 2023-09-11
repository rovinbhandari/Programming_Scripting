//author : Parag Gupta
//accepted in : 
// contest :
/* algo: 
*/

#include<cstdio>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>

using namespace std;
#define LL long long int
#define MX 100005
#define f(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define fe(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define fm(x,y,z) for((x)=(y) ; (x)>(z) ; (x)--)
#define FLUSH fflush(stdout)
#define copy(dest,src,size) memcpy(dest,src,size)
#define NL {printf("\n");}
#define PB push_back
#define MP make_pair

int main(){
  LL i,j,k,t;
  LL n,m;
  LL stick[MX];
  LL box[MX];
  LL l,b,h;
  scanf("%lld",&t);
  while(t--){
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++){
        scanf("%lld",&stick[i]);
    }
    LL mx = 0;
    for(i=0;i<m;i++){
        scanf("%lld %lld %lld",&l,&b,&h);
        box[i] = l*l+b*b+h*h;
        if( box[i] > mx ) mx = box[i];
    }
    LL ans = 0;
    for(i=0;i<n;i++){
        if( stick[i]*stick[i] <= mx ) ans++;
    }
    printf("%lld\n",ans);
  }
  return 0;
}
/* problem:
*/

