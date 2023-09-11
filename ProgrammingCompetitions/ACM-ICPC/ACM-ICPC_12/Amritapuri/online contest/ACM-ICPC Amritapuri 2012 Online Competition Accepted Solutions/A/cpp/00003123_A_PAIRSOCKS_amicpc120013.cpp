#include<iostream>
using namespace std;

int main(){
	int T;
	char s[100];
	cin>>T;
	int flag;
	while(T-->0){
		int a[4];
		flag=0;
		a[0]=0; a[1]=0; a[2]=0; a[3]=0;
		cin>>s;
		for(int i=0;s[i]!='\0';i++){
			if(s[i]=='R'){
				a[0]+=1;
			}
			else if(s[i]=='G'){
				a[1]+=1;
			}
			else if(s[i]=='B'){
				a[2]+=1;
			}
			else if(s[i]=='W'){
				a[3]+=1;
			}
		}
		for(int i=0;i<4;i++){
			if(a[i]%2!=0){
				flag=1;
			}
		}
		if(flag==0){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}
