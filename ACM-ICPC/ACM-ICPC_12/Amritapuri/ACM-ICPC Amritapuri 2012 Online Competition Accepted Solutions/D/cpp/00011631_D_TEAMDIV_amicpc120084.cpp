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
#define MX 20005
#define f(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define fe(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define fm(x,y,z) for((x)=(y) ; (x)>(z) ; (x)--)
#define FLUSH fflush(stdout)
#define copy(dest,src,size) memcpy(dest,src,size)
#define NL {printf("\n");}
#define PB push_back
#define MP make_pair

int color[MX];

vector<int> rival[MX];

int num_sets = 0;
int n;
#define MOD 1000000007
LL power(LL base,LL n){ 
    LL ans=1;
    while(n){
        if(n&1==1) ans = (ans*base) % MOD;
        base =(base * base) % MOD;
        n=(n>>1);
    }
    return ans%MOD;
}

int dfs(int v){
    for(int i=0;i<rival[v].size();i++){
        if( color[ rival[v][i] ] == color[v] ) return -1;
        if( color[rival[v][i] ]== 0 ) {
            if(color[v]==1)  color[ rival[v][i] ] = 2;
            else color[ rival[v][i]] = 1;
            if( dfs(rival[v][i]) == -1 ) return -1;
        }
    }
}

int calc(){
    for(int i=0;i<n;i++){
        if( color[i]==0){
               color[i] = 1;
               if( dfs(i) == -1 ) return -1;  
               num_sets++;
        }
    }
    return 0;
}

int main(){
  int t,i,j,k;
  scanf("%d",&t);
  int temp;
  while(t--){
    num_sets = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        rival[i].clear();
        color[i] = 0;
    }

    for(i=0;i<n;i++){
        scanf("%d",&k);
        for(j=0;j<k;j++){
            scanf("%d",&temp);
            rival[i].push_back( temp );
            rival[temp].push_back( i );
        }
    }
    if( calc() == -1) {
        printf("0\n");
    }
    else{
        if( num_sets == 0) 
        printf("0\n");
        else 
         printf("%lld\n", power(2,num_sets));
    }
  }
  return 0;
}
/* problem:
*/

