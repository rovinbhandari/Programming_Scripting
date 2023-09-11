#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main ()
{
	int no_testcases;
	scanf("%d",&no_testcases);
	
	for (int k=1; k<=no_testcases; k++) {
		
		char input[100];
		scanf("%s",input);
		int i=0,R=0,B=0,G=0,W=0;   ///all shud be zero
		
		
		while (input[i]=='R' || input[i]=='B' || input[i]=='G' || input[i]=='W') {
			if (input[i]=='R') {
				R=(R==0)?1:0;
			}
			if (input[i]=='G') {
				G=(G==0)?1:0;
			}
			if (input[i]=='B') {
				B=(B==0)?1:0;
			}
			if (input[i]=='W') {
				W=(W==0)?1:0;
			}
			i++;
		}
		if (R==0 && B==0 && G==0 && W==0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		//printf("%lf\n",answer);
	}
	
	
	return 0;
}