#include<stdlib.h>
#include<string.h>
int main() {
	int t;
	scanf("%d",&t);
	int j;
	for (j=0; j<t; j++) {
		char a[100];
		scanf("%s", a);
		int len = strlen(a),c1=0, c2=0, c3=0, c4=0, i;
		for (i=0; i<len; i++) {
			if (a[i]=='R') {
				c1++;
			} else if (a[i]=='G') {
				c2++;
			} else if (a[i]=='B') {
				c3++;
			} else {
				c4++;
			}
		}
		if (!(c1%2 || c2%2 || c3%2 || c4%2)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
