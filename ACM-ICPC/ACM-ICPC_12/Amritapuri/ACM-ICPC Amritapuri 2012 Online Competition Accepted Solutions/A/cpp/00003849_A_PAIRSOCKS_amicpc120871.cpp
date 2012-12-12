//#include<cstdio>
#include<iostream>
#include<string>
using namespace std;


#define MAIN int main()
#define FOR(i,a,b) for(i=a; i<b; i++)


MAIN{
int t, i;
cin>>t;
string s;
int arr[4];
bool flag;
while(t--){
cin>>s;
FOR(i, 0, 4) arr[i]=0;
for(i=0; i<s.length(); i++){
switch(s[i]){
case 'R' : arr[0]++; break;
case 'G' : arr[1]++; break;
case 'B' : arr[2]++; break;
case 'W' : arr[3]++; break;
}
}

flag=true;
FOR(i, 0, 4) if(arr[i]%2==1) {flag=false; cout<<"NO"<<endl; break;}
if(flag) cout<<"YES"<<endl;
}

}
