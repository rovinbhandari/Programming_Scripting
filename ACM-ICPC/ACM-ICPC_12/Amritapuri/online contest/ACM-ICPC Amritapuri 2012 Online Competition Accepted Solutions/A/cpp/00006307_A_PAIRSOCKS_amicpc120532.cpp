#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <stdlib.h>

using namespace std;

#define FOR(I,A,B) for(int I= (A); I<(B); ++I)
#define REP(I,N) FOR(I,0,N)
#define S(N) scanf("%d", &N)
#define SL(N) scanf("%ld", &N)
#define SLL(N) scanf("%lld", &N)
#define PR(N) printf("%d\n",N)

typedef long long int LL;
typedef vector<int> vi;

int main ()
{
  int n;
  cin>>n;
  while(n--){
             int r=0, g=0, b=0, w=0;
             char ch[51];

             scanf("%s",&ch);
             if(strlen(ch)==0){
                                cout<<"YES"<<endl;
                                continue;
             }
             for(int i=0;i<strlen(ch);++i){
                                           if(ch[i]=='R') r++;
                                           else if(ch[i]=='G') g++;
                                           else if(ch[i]=='B') b++;
                                           else if(ch[i]=='W') w++;

                                           }

            if(r%2!=0 ||g%2!=0 || b%2!=0 || w%2!=0) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;

  }
  //system("pause");
  return 0;
}
