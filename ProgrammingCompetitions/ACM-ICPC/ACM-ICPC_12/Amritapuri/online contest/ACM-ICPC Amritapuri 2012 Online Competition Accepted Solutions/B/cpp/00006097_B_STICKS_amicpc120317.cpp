#include <iostream>
#include<stdio.h>

using namespace std;

int main ()
{
  ios::sync_with_stdio(false);
  int T = 0;
  int N,M;
  N = 0;
  M = 0;
  long unsigned int a=0;
  long unsigned int b=0;
  long unsigned int c=0;
  long unsigned int tempsum = 0;
  long unsigned int sum =0;
  long unsigned int count=0;
  int out[11];
  for (int i=0; i<11;i++) {
      out[i] = 0;
  }
  long unsigned int L[50010];
  for (int i=0; i<50010;i++) {
      L[i] = 0;
  }
  
  
  cin >> T;
  for (int t=0; t<T; t++) {
      sum =0;
      cin >> N >> M;
      for (int n=0; n<N; n++) {
          cin >> L[n];
      }    
      for (int m=0;m<M;m++) {
          cin >> a >> b >> c;
          tempsum = a*a + b*b + c*c;
          if (tempsum > sum) {
              sum = tempsum; 
          }
      }
      count =0;
      for (int n=0;n<N;n++) {
          if (L[n]*L[n]<=sum) {
             count = count + 1;
          }
      }
      out[t] = count;
  }
  
  for (int t=0; t<T;t++) {
      cout << out[t]<<endl;
  }
  
  
  return 0;
}

