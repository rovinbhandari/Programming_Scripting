#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(;t>0;t--){
		string S;
		cin>>S;
		int r = 0;
		int g =0;
		int b = 0;
		int w = 0;
		for(int i = 0;i < S.length();i++){
			if(S[i] == 'R')
				r++;
			else if(S[i] == 'G')
				g++;
			else if(S[i] == 'B')
				b++;
			else if(S[i] == 'W')
				w++;		
		}
		if(r%2 ==0 && g%2 ==0 && b%2 ==0 && w%2 ==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;	
	}
}
