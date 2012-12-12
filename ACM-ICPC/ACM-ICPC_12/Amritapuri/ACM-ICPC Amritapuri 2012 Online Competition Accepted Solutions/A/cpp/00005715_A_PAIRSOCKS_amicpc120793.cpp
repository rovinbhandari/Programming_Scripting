#include<iostream>

using namespace std;

int main(){
	int T;
	cin>>T;
	for(int t = 0; t < T; t++){
		int r = 0, g = 0, b = 0, w = 0;
		string s;
		cin>>s;
		if(s.length() == 0){
			cout<<"NO\n";
		}
		for(int i = 0; i < s.length(); i++){
			if(s[i] == 'R'){
				r++;
			}
			if(s[i] == 'B'){
				b++;
			}
			if(s[i] == 'G'){
				g++;
			}
			if(s[i] == 'W'){
				w++;
			}
		}
		if(r%2 == 0 && b%2 == 0 && g%2 == 0 && w%2 == 0){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}