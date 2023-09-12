#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int t;
	cin >> t;
	bool r,g,b,w;
	char st[50];
	char c;

	for(int i = 0; i < t; i++){
		r = 0;
		g = 0;
		b = 0;
		w = 0;

		scanf("%s",st);
		for(int j=0;st[j]!='\0';j++){
			c=st[j];
			if(c == 'R'){
				r = !r;
			}
			else if(c == 'G'){
				g = !g;
			}
			else if(c == 'B'){
				b = !b;
			}
			else if(c == 'W'){
				w = !w;
			}
		}
		if(r || g || b || w){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
	}
	return 0;
}