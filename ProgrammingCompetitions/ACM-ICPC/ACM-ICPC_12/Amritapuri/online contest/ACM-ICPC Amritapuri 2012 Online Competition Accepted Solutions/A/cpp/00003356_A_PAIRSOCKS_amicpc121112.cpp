#include<iostream>
#include <algorithm>
#include<stdio.h>
int main(){
int t;
scanf("%d",&t);
while(t--){
char a[51];
int flag=1;
scanf("%s",a);
int i,count;
std::string s = a;
for(i=0;s[i]!='\0';i++){
count=std::count(s.begin(), s.end(), a[i]);
if(count%2!=0)flag=0;
}
if(flag) printf("YES\n");
else printf("NO\n");
}
return 0;
}