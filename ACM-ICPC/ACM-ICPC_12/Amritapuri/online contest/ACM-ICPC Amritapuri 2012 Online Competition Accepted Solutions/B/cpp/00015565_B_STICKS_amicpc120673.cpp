#include<iostream>
using namespace std;
int main(){
int i,j,k,t,n,m;
cin>>t;
while(t>0){
cin>>n>>m;
long long int s[n],d,a,b,c,m_d,c_t;
for(i=0;i<n;i++){
cin>>s[i];
}
m_d=c_t=0;
for(i=0;i<m;i++){
cin>>a>>b>>c;
d=a*a+b*b+c*c;
if(d>m_d){
m_d=d;
}
}
for(i=0;i<n;i++){
if(s[i]*s[i]<=m_d) c_t++;
}
cout<<c_t<<endl;
t--;
}
return 0;
}


