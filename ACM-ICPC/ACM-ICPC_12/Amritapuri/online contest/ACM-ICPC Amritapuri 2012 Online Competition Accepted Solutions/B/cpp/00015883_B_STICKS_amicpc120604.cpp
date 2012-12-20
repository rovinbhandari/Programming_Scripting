#include<iostream>
#include <cstdio>
 
using namespace std;
 
int main(){
int i,j,k,t,n,m,x;
scanf ("%d",  &t);
while(t > 0){
scanf ("%d %d", &n, &m);
long long s[n], d , a , b , c ,ld ,count;
for(i=0;i<n;i++){
cin>>s[i];
}
 
ld = count = 0;
for(i = 0; i < m; i++){
scanf ("%lld %lld %lld", &a, &b, &c);
d=a*a+b*b+c*c;
if(d > ld){
ld=d;
}
}
for(i = 0;i < n; i++){
if(s[i]*s[i]<=ld) count++;
}
printf ("%lld\n", count);
t--;
}
}
