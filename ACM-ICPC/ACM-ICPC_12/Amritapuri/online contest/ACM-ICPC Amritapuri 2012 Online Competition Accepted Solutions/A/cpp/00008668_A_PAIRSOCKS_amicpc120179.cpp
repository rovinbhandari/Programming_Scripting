#include<iostream>

using namespace std;

int main(){
	int t, i;
	char s[51];
	bool b, r, g, w;
	cin>>t;
	while(t--){
		i=0;
		b=r=g=w=true;
		cin>>s;
		while(s[i]!='\0'){
			switch(s[i]){
			case'B':b=!b;
				break;
			case'R':r=!r;
				break;
			case'W':w=!w;
				break;
			case'G':g=!g;
				break;
			}
			i++;
		}
		if(b&&g&&r&&w)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}