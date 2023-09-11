#include<iostream>
#include<cstdio>
using namespace std;


int main(){
	int tests;
	scanf("%d\n",&tests );
	char c;
	//cout<<tests<<endl;
	int freq[4];
	int r,g,b,w;
	while(tests--){
		r = g = b =w = 0;
		c = getchar();
		while(c!='\n' && c!= EOF){
			if(c == 'R') {r++; c = getchar() ;continue;}
			if(c == 'G') {g++ ; c = getchar() ; continue;}
			if(c == 'B') {b++ ; c = getchar() ; continue;}
			else {w++; c = getchar() ;}

		}
		//cout<<r<<" "<<g<<" "<<b<<" "<<w<<endl;
		if((r%2 == 0) && (g%2 == 0) && (b%2==0) &&(w%2==0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}