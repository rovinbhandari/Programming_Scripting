#include<iostream>
#include<string>
using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2
#define WHITE 3

int main(){
	int i,t,length;
	int pair[4];
	string socks;	
	cin>>t;
	while(t--){
		for(i=0;i<=3;i++){
			pair[i]=0;
		}
		socks.clear();
		cin>>socks;
		length=socks.length();
		for(i=0;i<length;i++){
			if(!socks.compare(i,1,"R") ){
				pair[RED]=1-pair[RED];				
			}
			else if(!socks.compare(i,1,"G") ){
				pair[GREEN]=1-pair[GREEN];
			}
			else if(!socks.compare(i,1,"B") ){
				pair[BLUE]=1-pair[BLUE];	
			}
			else {
				pair[WHITE]=1-pair[WHITE];
			}
		}
		for(i=0;i<=3;i++){
			if(pair[i]!=0) break;
		}
		if(i==4){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}
