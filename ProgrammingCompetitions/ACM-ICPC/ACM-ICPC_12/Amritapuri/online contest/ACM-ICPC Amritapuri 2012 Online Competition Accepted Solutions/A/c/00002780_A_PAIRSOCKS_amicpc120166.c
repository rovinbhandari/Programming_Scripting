#include<stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	while(N--){
		char c[100];
		int r=0,b=0,g=0,w=0;
		scanf("%s",c);
		int i;
		for(i=0;c[i]!=0;i++){
			if(c[i]=='R')r++;
			if(c[i]=='G')g++;
			if(c[i]=='B')b++;
			if(c[i]=='W')w++;
		}
		if(r%2==0 && g%2==0 && b%2==0 && w%2==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}


