#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int t;
	scanf ("%d", &t);
	while(t--){
		char s[100];
		scanf ("%s", s);
		int i;
		int rctr = 0, bctr =0, gctr =0, wctr =0;
		for(i=0;s[i] != '\0'; i++){
			if(s[i] == 'R'){
				rctr ++;
			}
			if(s[i] == 'G'){
				gctr ++;
			}
			if(s[i] == 'B'){
				bctr ++;
			}
			if(s[i] == 'W'){
				wctr ++;
			}
		}

		if(rctr%2==0 && gctr%2 ==0 && bctr%2 ==0 && wctr%2 ==0){
			printf ("YES\n");
		}
		else {
			printf ("NO\n");
		}
	}

	return 0;
}
