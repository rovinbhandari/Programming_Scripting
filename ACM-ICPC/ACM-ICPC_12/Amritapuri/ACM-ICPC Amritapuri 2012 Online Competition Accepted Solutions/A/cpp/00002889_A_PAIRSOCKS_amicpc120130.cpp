#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<deque>

#define FOR(i,j,k,l) for(((i)=(j));((i)<(k));((i)+=(l)))
//#define min(a,b) ((a<b)?(a):(b))
//#define max(a,b) ((a>b)?(a):(b))
#define LL long long int;
#define LD long double;

using namespace std;

int main(){
  int x,y,z,i,j,k,n;  
  int nin,inum;
  char st[1010];
    cin>>nin;
    
    FOR(inum,0,nin,1){
        //each test case
      cin>>n;
      int r=0,w=0,b=0,g=0;
      scanf("%s",st);
      int l=strlen(st);
      for(i=0;i<l;i++){
	if(st[i]=='R'){
	  r++;
	}
	else if(st[i]=='W'){
	  w++;
	}
	else if(st[i]=='B'){
	  b++;
	}
	else if(st[i]=='G'){
	  g++;
	}
      }
      if(((r%2)==0)&&((b%2)==0)&&((g%2)==0)&&((w%2)==0)){
	cout<<"YES"<<endl;
      }
      else{
	cout<<"NO"<<endl;
      }
      
    }

    return 0;
}
