#include<stdio.h>
int main()
{
	int r,g,b,w;
	char str[10000];
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%s",str);
		w = r = g = b = 0;
		int i = 0;
		while(str[i] != '\0') {
			if(str[i] == 'R'){
				r++;
			}
			if(str[i] == 'G'){
				g++;
			}
			if(str[i] == 'B'){
				b++;
			}
			if(str[i] == 'W'){
				w++;
			}
			i++;
		}
		if(r%2 || g%2 || b%2 || w%2) {
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}

