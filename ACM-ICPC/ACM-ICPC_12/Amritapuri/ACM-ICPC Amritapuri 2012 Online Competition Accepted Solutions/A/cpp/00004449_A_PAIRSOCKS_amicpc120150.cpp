#include<iostream>
#include<cstring>
using namespace std;
int main(){
int r,g,b,t,w,i,x;
char s[100];
cin>>t;
while(t>0){
cin>>s;
r=g=b=w=0;
x=strlen(s);
i=0;
while(i<x){
if(s[i]=='R'){
if(r==0) r++;
else r--;
}
else if(s[i]=='G'){
if(g==0) g++;
else g--;
}
else if(s[i]=='B'){
if(b==0) b++;
else b--;
}
else if(s[i]=='W'){
if(w==0) w++;
else w--;
}
i++;
}
if(r+g+w+b==0) cout<<"YES\n";
else cout<<"NO\n";
t--;
}
}
