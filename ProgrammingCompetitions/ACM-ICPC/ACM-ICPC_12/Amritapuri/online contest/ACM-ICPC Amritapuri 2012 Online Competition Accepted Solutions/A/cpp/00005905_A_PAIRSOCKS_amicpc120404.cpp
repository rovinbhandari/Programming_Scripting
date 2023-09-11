#include <iostream>
#include <string>

using namespace std;

int main(){
	int T;
	string ip,res;
	//char* ip;
	int numSocks[4];
	
	cin>>T;
	for(int i=0; i<T; i++){
		cin>>ip;
		for(int i=0; i<4; i++){
			numSocks[i]=0;
		}
		int j=0;
		int l=ip.length();
		while(j<l){
			//if(ip[j]=='\0') break;
			if(ip[j]=='R') numSocks[0]++;
			else if(ip[j]=='W') numSocks[1]++;
			else if(ip[j]=='B') numSocks[2]++;
			else if(ip[j]=='G') numSocks[3]++;
			j++;
		}
		if(((numSocks[0] & 1) == 0) && ((numSocks[1] & 1) == 0) && ((numSocks[2] & 1) == 0) && ((numSocks[3] & 1) == 0)){
			res="YES";
		}
		else res="NO";
		cout<<res<<endl;
	}
	return 0;
}
