#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
 long long int n,m;
 scanf("%lld %lld",&n,&m);
 int count=0;
 long long int p[n];
 for(int i=0;i<n;i++){
 scanf("%lld",&p[i]);
 }
 long long int l[m],h[m],b[m];
 double d[m];
 long long int max=0;
 for(int i=0;i<m;i++){
 scanf("%lld %lld %lld",&l[i],&b[i],&h[i]);
 d[i]=sqrt((l[i]*l[i])+(b[i]*b[i])+(h[i]*h[i]));
 if(d[i]>max)max=d[i];
 }
 for(int i=0;i<n;i++){
 
 if(p[i]<=max)count++;
 }
 printf("%d\n",count);
 }
 return 0;
 }
 
 
