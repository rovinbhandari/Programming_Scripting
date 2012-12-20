#include<stdio.h>
int main(void){
	char input[55];
	int t, i;
	int f=0;
	int counter[4] = {0,0,0,0};
	scanf("%d", &t);
	while(t>0){
		t--;
		f=0;
		for(i=0; i<4; i++){
			counter[i]=0;
		}
		scanf("%s", &input);
		i=0;
		while(input[i]!='\0'){
			if(input[i]=='R')
				counter[0]++;
			else if(input[i]=='G')
				counter[1]++;
			else if(input[i]=='B')
				counter[2]++;
			else
				counter[3]++;
			i++;	
		}
		for(i=0; i<4; i++){
			if (counter[i]%2==1){
				f=1;
			}
		}
		if(f==1)
			printf("NO\n");
		else
			printf("YES\n");		
	}
	return 0;
}