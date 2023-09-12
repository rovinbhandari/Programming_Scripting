#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<deque>
using namespace std;

int main(){
   //freopen("input.in","r",stdin);
   //freopen("output.out","w",stdout);
   int t;
   scanf("%d",&t);
   while(t--){
      int n,m,temp;
      scanf("%d %d",&n,&m);
      int sticks[60001];
      double a,b,c,temp1,diag=-1;
      for(int i=0;i<n;i++){
         scanf("%d",&temp);
         sticks[i]=temp;
      }
      for(int i=0;i<m;i++){
         cin>>a>>b>>c;
         temp1=(sqrt(a*a+b*b+c*c));
         if(temp1>diag)diag=temp1;
      }
      int count=0;
      for(int i=0;i<n;i++){
         temp=sticks[i];
         if(temp<=diag)count++;
      }
      printf("%d\n",count);
   }
   return 0;
}
