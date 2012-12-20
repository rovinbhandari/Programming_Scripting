#include <iostream>
#include <cstdio>
#include <cmath>
#define size 50010
#define l 0
#define b 1
#define h 2


using namespace std;

long long sticks[size],boxes[size][3];

 int main(){
  long long cal;
  long long t,n,m,i,max=0,count=0;
  long long st;
  scanf("%lld",&t);
  while(t--){	
   max = 0;
   count = 0;
   scanf("%lld %lld",&n,&m);
   for(i=0;i<n;i++)
    scanf("%lld",sticks+i);
   for(i=0;i<m;i++){
    scanf("%lld %lld %lld",&boxes[i][l],&boxes[i][b],&boxes[i][h]);
    st = (boxes[i][l]*boxes[i][l]) + (boxes[i][b]*boxes[i][b]) + (boxes[i][h]*boxes[i][h]);
    cal = (long long)sqrt((double)st);
    if(cal>max)
     max = cal;
   }
   for(i=0;i<n;i++){
    if(sticks[i]<=max)
     count++;
   }
   printf("%lld\n",count);
  }
 return 0;
 }
