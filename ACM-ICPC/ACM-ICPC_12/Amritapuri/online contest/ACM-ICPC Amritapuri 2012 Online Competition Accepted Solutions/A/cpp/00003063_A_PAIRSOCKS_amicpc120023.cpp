#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
	int T;cin>>T;
	for(int i=0;i<T;i++){
		string s;
		cin>>s;
		vector<int> a;//0-r,g-1,b-2,w-3
		a.resize(4);
		for(int j=0;j<s.length();j++){
			if(s[j]=='R')
				a[0]++;
			else if(s[j]=='G')
				a[1]++;
			else if(s[j]=='B')
				a[2]++;
			else if(s[j]=='W')
				a[3]++;
		}
		//Processing done
		bool flag=true;
		for(int j=0;j<4;j++){
			if(a[j]%2 !=0)
				flag = false;
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
