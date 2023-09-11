#include <stdio.h>
#include <string.h>

#define R 0
#define G 0
#define B 0
#define W 0

int main(int argc, const char *argv[])
{
	int T;
	scanf("%d", &T);
	char colors[55];
	int i;
	int freq[4];
	while(T--) {
		freq[0] = freq[1] = freq[2] = freq[3] = 0;
		scanf("%s", colors);
		for (i = 0; i < strlen(colors); i++) {
			switch (colors[i]) {
				case 'R':
					freq[0]++;
					break;
				case 'G':
					freq[1]++;
					break;
				case 'B':
					freq[2]++;
					break;
				case 'W':
					freq[3]++;
					break;
			}
		}
		if ((freq[0] % 2 == 0) && (freq[1] % 2 == 0) && (freq[2] % 2 == 0) && (freq[3] % 2 == 0)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
