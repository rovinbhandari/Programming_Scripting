#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<deque>
#include<cmath>
#define FOR(i,j,k,l) for(((i)=(j));((i)<(k));((i)+=(l)))
//#define min(a,b) ((a<b)?(a):(b))
//#define max(a,b) ((a>b)?(a):(b))
#define LL long long int;
#define LD long double;

long long int ls[51000];
// struct box{
//   int l,b,h;
// };
// box bs[51000];

using namespace std;

int main(){
  long long int x,y,z,i,j,k,n,m,count;  
  int nin,inum;
  long long int lmax,lhere;
    cin>>nin;
    
    FOR(inum,0,nin,1){
        //each test case
      cin>>n>>m;
      lmax=0;count=0;
      for(i=0;i<n;i++){
	scanf("%lld",&ls[i]);
      }
      for(i=0;i<m;i++){
	scanf("%lld%lld%lld",&x,&y,&z);
	lhere=sqrt(x*x+y*y+z*z);
	if(lhere>lmax)
	  lmax=lhere;
      }
      for(i=0;i<n;i++){
	if(ls[i]<=lmax){
	  count++;
	}
      }
      cout<<count<<endl;

    }

    return 0;
}
