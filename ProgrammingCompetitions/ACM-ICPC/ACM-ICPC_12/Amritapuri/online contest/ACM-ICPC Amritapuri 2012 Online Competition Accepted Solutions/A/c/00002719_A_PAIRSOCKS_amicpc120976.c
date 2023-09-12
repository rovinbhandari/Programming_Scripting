#include <stdio.h>
#include <string.h>

int main(){
	int n,i;
	char str[55];

	scanf("%d",&n);

	while(n--){
		int a[5]={0};
		scanf("%s",str);

		for(i=0;i<strlen(str);++i){
			if(str[i]=='R')
				++a[0];
			else if(str[i]=='G')
				++a[1];
			else if(str[i]=='B')
				++a[2];
			else if(str[i]=='W')
				++a[3];
		}

		if(a[0]%2==0 && a[1]%2==0 && a[2]%2==0 && a[3]%2==0){
			printf("YES\n");
		}
			else
			printf("NO\n");
		
	}

	return 0;
}