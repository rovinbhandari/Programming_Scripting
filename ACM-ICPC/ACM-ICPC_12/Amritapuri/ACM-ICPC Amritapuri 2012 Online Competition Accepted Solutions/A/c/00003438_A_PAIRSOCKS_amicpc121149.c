#include<stdio.h>
#include<string.h>
int main(){
	int T,i,j,count,isans;
	char str[60];
	scanf("%d",&T);
	while(T--){
	strcpy(str,"");
	isans=0;
	scanf("%s",str);
		for(i=0;;i++){
			if(str[i]=='\0')
				break;
			count=0;
			for(j=0;;j++){
				if(str[j]=='\0')
					break;
				if(str[j]==str[i])
					count++;
				
			}
			if(count%2!=0)
				isans=1;
				
		}
	if(isans==0)
		printf("YES\n");
	else
		printf("NO\n");
	}
	return 0;
}
