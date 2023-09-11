#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
using namespace std;


int main(){
  
  int n,i;
  cin >> n;
  char c;
  string s;
  bool num[4];// RGBW
  for (i=0; i<4; i++) {
    num[i]=true;
  }
  bool *ans;
  ans = new bool[n];
  c=getchar();
   int k=n-1;
  while (n>0){
    n--;
    c=getchar();
    
    while (c!='\n'){
      switch(c){
        case 'R':
          num[0]=!num[0];
        case 'G':
          num[1]=!num[1];
        case 'B':
          num[2]=!num[2];
        case 'W':
          num[3]=!num[3];
      }
     c=getchar();
    }
    ans[n]=true;
    for (i=0; i<4; i++){
      if (num[i]==false) {
        ans[n]=false; break;}
        }
     for (i=0; i<4; i++) {
    num[i]=true;
    }
  }
  for (int j=k; j>=0; j--){
    if (ans[j]==true) cout << "YES" <<endl;
    else cout << "NO" <<endl;
    }
    
    return 0;
    }
    
    
    
    
    
    
    
    
    
    
