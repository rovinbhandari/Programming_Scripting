#include<iostream>
#include<cstring>
#include<vector>
#include<stdio.h>
using namespace std;
int main(){
char s[51];
int t;

scanf("%d",&t);
while(t--){
int a[]={0,0,0,0};
scanf("%s",s);
for(int i=0;i<strlen(s);i++){
if(s[i]=='R') a[0]++;
else if(s[i]=='G') a[1]++;
else if(s[i]=='B') a[2]++;
else if(s[i]=='W') a[3]++;
}
if(a[0]%2==0 && a[1]%2==0 && a[2]%2==0 && a[3]%2==0) cout<<"YES"<<endl;
else cout<<"NO"<<endl;

}


}
