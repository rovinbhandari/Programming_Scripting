#include <stdio.h>

int main() {
	int T, i;
	char c[100];
	int r,g,b,w;
	scanf("%d", &T);
	while (T--) {
		r=g=b=w=0;
		scanf("%s", c);
		for (i = 0; c[i] != '\0'; i++) {
			switch (c[i]) {
				case 'R':
					r++;
					break;
				case 'B':
					b++;
					break;
				case 'G':
					g++;
					break;
				case 'W':
					w++;
					break;
			}
		}
		if (r%2 || b%2 || g%2 || w%2) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}
