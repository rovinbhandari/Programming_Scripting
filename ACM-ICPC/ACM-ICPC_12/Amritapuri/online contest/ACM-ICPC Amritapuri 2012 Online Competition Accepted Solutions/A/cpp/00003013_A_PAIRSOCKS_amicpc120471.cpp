#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int count[4], T;
	char input[64];

	scanf("%d", &T);
	while(T--) {
		scanf("%s", input);
		count[0] = count[1] = count[2] =  count[3] = 0;
		for(int i=0; i<strlen(input); i++) {
			switch(input[i]) {
				case 'R':
					count[0]++;
					break;
				case 'W':
					count[1]++;
					break;
				case 'G':
					count[2]++;
					break;
				default:
					count[3]++;
					break;
			}
		}
		
		if(count[0]%2==0 && count[1]%2==0 && count[2]%2==0 && count[3]%2==0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}