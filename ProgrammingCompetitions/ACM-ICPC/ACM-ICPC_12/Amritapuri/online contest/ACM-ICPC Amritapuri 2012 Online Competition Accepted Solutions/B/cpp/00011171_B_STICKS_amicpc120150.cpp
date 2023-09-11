#include<iostream>
using namespace std;
int main(){
int i,j,k,t,n,m,x;
cin>>t;
while(t>0){
cin>>n>>m;
long long int s[n],d,a,b,c,md,ct;
for(i=0;i<n;i++){
cin>>s[i];
}
md=ct=0;
for(i=0;i<m;i++){
cin>>a>>b>>c;
d=a*a+b*b+c*c;
if(d>md){
md=d;
}
}
for(i=0;i<n;i++){
if(s[i]*s[i]<=md) ct++;
}
cout<<ct<<endl;
t--;
}
}
