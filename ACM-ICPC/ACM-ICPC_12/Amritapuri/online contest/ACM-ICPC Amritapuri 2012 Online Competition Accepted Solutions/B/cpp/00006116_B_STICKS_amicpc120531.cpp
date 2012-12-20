#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;


long long int len[50005];

int main()
{
 long long int t,n,m,i,l,b,h,diag,max,count;
 cin>>t;
 while(t--)
 {
  cin>>n>>m;
  for(i=0;i<n;i++)
  {
   cin>>len[i];
  }
  sort(len,len+n);
  
 // for(i=0;i<n;i++)
   //printf("%d ",len[i]);
  //printf("\n"); 

  max=0;
  for(i=0;i<m;i++)
  { 
   cin>>l>>b>>h;
   diag=((l*l)+(b*b)+(h*h));
   diag=sqrt(diag);
   if(diag>=max)
    max=diag;
  }
  
  for(i=n-1;i>=0;i--)
  {
   if(max>=len[i])
   {
    //i++;
    break;
   }
  }
  printf("%d\n",i+1);
 }
 return 0;
}
