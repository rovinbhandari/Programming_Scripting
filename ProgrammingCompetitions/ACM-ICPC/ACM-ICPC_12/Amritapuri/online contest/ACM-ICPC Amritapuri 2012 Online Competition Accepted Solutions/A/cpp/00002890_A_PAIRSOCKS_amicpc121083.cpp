#include<iostream>

using namespace std;

int main() {

	int T, r, g, b, w;
	char a[51];	


	cin>>T;
	

	for (int i=0; i<T; i++) {

		r = g = b = w = 0;

		cin>>a;

		for (int i = 0; a[i]!='\0'; i++) {

			switch(a[i]) {

				case 'R': r++;break;
				case 'G': g++;break;
				case 'B': b++;break;
				case 'W': w++;break;
			}
		}

		if (r%2==0 && g%2==0 && b%2==0 && w%2==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	
		
	}

	return 0;
}
