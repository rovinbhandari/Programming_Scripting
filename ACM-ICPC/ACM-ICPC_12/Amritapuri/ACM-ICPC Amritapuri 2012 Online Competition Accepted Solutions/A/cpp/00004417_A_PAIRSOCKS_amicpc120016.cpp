#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0; i<t; i++){ 
		string str;
		int R = 0, G = 0, B = 0, W = 0;
		cin>>str;
		int l = str.length();
		if (l == 0) cout<<"NO"<<endl;
		else{
			for(int i=0; i<l; i++){
				if (str[i] == 'R') R++;
				if (str[i] == 'G') G++;
				if (str[i] == 'B') B++;
				if (str[i] == 'W') W++;	
			}
			if ((R%2 == 0) && (G%2 == 0) && (B%2 == 0) && (W%2 == 0)) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
		return 0;
}
