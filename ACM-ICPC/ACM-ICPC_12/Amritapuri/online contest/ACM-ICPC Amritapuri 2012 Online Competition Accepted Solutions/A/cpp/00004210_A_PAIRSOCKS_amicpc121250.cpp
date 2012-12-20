#include<iostream>
#include<string>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
int strl,r=0,g=0,b=0,w=0;
string str;
cin>>str;
strl=str.length();

for(int i=0;i<strl;i++)
{
if(str[i]=='R'){
++r;}
else if(str[i]=='G'){
++g;}
else if(str[i]=='B'){
++b;}
else if(str[i]=='W'){
++w;
}
}
if(r%2==0 && g%2==0 && b%2==0 && w%2==0){
cout<<"YES\n";}
else{
cout<<"NO\n";}
}

return 0;
}
