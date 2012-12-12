#include <cstdio>
int main(){
	char s[50];
	int T,r,g,b,w;
	scanf("%d",&T);
	while (T!=0){
		r=0;
		g=0;
		b=0;
		w=0;
		scanf("%s",s);
		int i=0;
		while (s[i]!='\0'){
			if (s[i]=='r' || s[i]=='R')
				r++;
			else if (s[i]=='g' || s[i]=='G')
				g++;
			else if (s[i]=='b' || s[i]=='B')
				b++;
			else if (s[i]=='w' || s[i]=='W')
				w++;
			i++;
		}
		if (r%2==0 && b%2==0 && g%2==0 && w%2==0)
			printf("YES\n");
		else
			printf("NO\n");
		T--;
	}
	return 0;
}