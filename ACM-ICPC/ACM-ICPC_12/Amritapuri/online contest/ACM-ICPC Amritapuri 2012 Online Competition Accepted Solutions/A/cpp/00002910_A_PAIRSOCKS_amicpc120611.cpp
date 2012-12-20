#include <iostream>
using namespace std;

main(){
	int N;
	cin >> N;
	while(N-- > 0){
		int R = 0, G = 0, B = 0, W = 0;
		string s;
		cin >> s;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'R')	R++;
			else if(s[i] == 'G')	G++;
			else if(s[i] == 'B')	B++;
			else if(s[i] == 'W')	W++;
		}
		if((R % 2 == 0) && (G % 2 == 0) && (B % 2 == 0) && (W % 2 == 0))
			cout << "YES" << endl;
		else	cout << "NO" << endl;
	}
}
