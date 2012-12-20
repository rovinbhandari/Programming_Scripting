#include<iostream>
#include<cstdio>
using namespace std;
int main(){
int t;
cin>>t;
getchar();
while(t--)
{
 char c;
 int cr=0,cg=0,cw=0,cb=0;
 while((c=getchar())!='\n'){
 if(c=='R')cr++;
 if(c=='B')cb++;
 if(c=='W')cw++;
 if(c=='G')cg++;
 }
 if((cr%2==0)&&(cw%2==0)&&(cg%2==0)&&(cb%2==0)){cout<<"YES\n";}
 else{cout<<"NO\n";}
 //getchar();
 }
 
 return 0;
 }
 
