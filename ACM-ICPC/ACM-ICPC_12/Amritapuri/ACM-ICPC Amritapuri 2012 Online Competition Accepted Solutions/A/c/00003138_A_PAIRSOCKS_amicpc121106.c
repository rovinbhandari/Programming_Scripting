#include<stdio.h>
#include<stdlib.h>

int main(){
	int t;
	int i=0;	
	int j,R,B,G,W;		
	scanf("%d",&t);
	char* socks = (char*)malloc(50*sizeof(char));
	for(i=0;i<t;i++){
		R=0;
		W=0;
		G=0;
		B=0;		
		scanf("%s",socks);

		for(j=0;socks[j]!='\0';j++){
			switch(socks[j]){
				case 'B': B++;
						 break;
				case 'R':R++;
						 break;
				case 'W':W++;
						 break;
				case 'G':G++;
						 break;
			}
		}
		if(R%2==0 && G%2==0 && B%2==0 && W%2==0){
			printf("YES\n");
		}
		else{
			printf("NO\n");		
		}
	}

	return 0;
}
