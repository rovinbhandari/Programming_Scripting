#include <stdio.h>

int main(){
	int t, i, j, r, g, b, w, ch;

	scanf("%d", &t);
	getchar();
	while(t--){
		r = g = b = w = 0;
		while((ch = getchar()) != '\n'){
			switch(ch){
				case 'R':
					r++;
					break;
                                case 'G':
					g++;
					break;
				case 'B':
					b++;
					break;
				case 'W':
					w++;
					break;
			}
			
		}
		if(r % 2 == 0 && g % 2 == 0 && b % 2 == 0 && w % 2 == 0)
				printf("YES\n");
		else
				printf("NO\n");
	}
	return(0);
}
