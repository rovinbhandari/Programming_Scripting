#include <iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		string s;
		int r=0,g=0,b=0,w=0;
		cin>>s;
		for(int i=0;i<s.length();i++){
			if(s[i]=='R')r++;
			if(s[i]=='G')g++;
			if(s[i]=='B')b++;
			if(s[i]=='W')w++;
		}
		if(r%2==0 && g%2==0 && b%2==0 && w%2==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

