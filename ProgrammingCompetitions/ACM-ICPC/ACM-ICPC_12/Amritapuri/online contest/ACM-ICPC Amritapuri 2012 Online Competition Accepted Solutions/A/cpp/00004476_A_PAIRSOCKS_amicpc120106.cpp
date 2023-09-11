#include<iostream>
using namespace std;
int main(){
int no_of_tcs;
char c[51];
int i = 0;
int j = 0;
int R,G,B,W;
R = 0;
G = 0;
B = 0;
W = 0;
cin >> no_of_tcs;
while(i < no_of_tcs){
	cin >> c;
	j = 0;
	R = 0; G = 0; B = 0; W = 0;
	while(c[j] != '\0'){
		if (c[j] == 'R'){R++;}
		if (c[j] == 'G'){G++;}
		if (c[j] == 'B'){B++;}
		if (c[j] == 'W'){W++;}
		j++;
	}
	if(R%2 == 0 && G%2 == 0 && B%2 == 0 && W%2 == 0){
		cout << "YES" << endl;
	}
	else { cout << "NO" << endl;}
	i++;
}
return 0;
}
