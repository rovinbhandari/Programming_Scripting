#include <iostream>
#include <string>
using namespace std;
int main() {
	int n,m[4]={0,0,0,0},f;
	string s;
	cin >> n;
	while(n>0) {
		cin >> s;f=0;
		for (int i = 0 ; i < 4 ; i++) {
			m[i] = 0;
		}	
		
		for(string::iterator itr = s.begin(); itr!=s.end(); itr++) {
			if(*itr == 'R') m[0]++;
			else if(*itr == 'G') m[1]++;
			else if(*itr == 'B') m[2]++;
			else if(*itr == 'W') m[3]++;
		}
		
		for(int i=0;i<4;i++) 
			if(m[i]%2) { cout << "NO" << endl;f=1; break; }
		if(f==0)
			cout << "YES" << endl;
		n--;
	}	
		return 0;
}
