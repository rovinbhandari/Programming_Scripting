#include<iostream>
using namespace std;
#include<string.h>
int main(){
int t,n;
int a,b,c,d;
a=b=c=d=0;
char str[50];
cin>>t;
while(t--){
cin>>str;
for(int i=0;i<strlen(str);i++){
switch(str[i]){
case 'R' : a++;
		break;
case 'W' : b++;
	break;
case 'G' :c++;break;
case 'B':d++;break;
}
}
if(a%2==0 &&b%2==0&&c%2==0&&d%2==0)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
a=b=c=d=0;
}
return 0;
}
