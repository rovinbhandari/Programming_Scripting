#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int t;
	cin>>t;
	string s;
	int c[4];
	while(t--){
		cin>>s;
		for (int i = 0; i < 4; ++i)
		{
			c[i] = 0;
		}
		for(int i = 0;i<s.length();i++){
			if(s[i] == 'R') c[0]++;
			if(s[i] == 'G') c[1]++;
			if(s[i] == 'W') c[2]++;
			if(s[i] == 'B') c[3]++;
		}
		int flag = 0;
		for (int i = 0; i < 4; ++i)
		{
			if(c[i]%2 != 0) {
				flag = 1;
				break;
			}	
		}
		if(flag == 0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}