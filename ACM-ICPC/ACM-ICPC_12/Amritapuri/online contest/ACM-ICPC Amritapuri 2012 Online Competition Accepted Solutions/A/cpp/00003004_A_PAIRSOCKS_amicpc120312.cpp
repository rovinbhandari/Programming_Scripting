#include<iostream>
#include<string>
using namespace std;
int main(){
	int t,i,c1,c2,c3,c4;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		c1=c2=c3=c4=0;
		for(i=0;i<s.size();i++){
			if(s[i]=='R')
				c1++;
			else if(s[i]=='G')
				c2++;
			else if(s[i]=='B')
				c3++;
			else c4++;
	  }
	  if(c1%2!=0||c2%2!=0||c3%2!=0||c4%2!=0)
	  	cout<<"NO\n";
	  else cout<<"YES\n";
	}
	return 0;
}
