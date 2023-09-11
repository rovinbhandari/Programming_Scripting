#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main() {
	int T,R,B,G,W,i,j;
	scanf("%d",&T);
	for(i=0; i<T; i++) {
		string c;
		cin>>c;
		R=G=B=W=0;
		for(j=0; j<c.size(); j++) {
			if(c[j]=='R') R++;
			else if(c[j]=='G') G++;
			else if(c[j]=='B') B++;
			else if(c[j]=='W') W++;
		}
		if(R%2==0 && G%2==0 && B%2==0 && W%2==0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
