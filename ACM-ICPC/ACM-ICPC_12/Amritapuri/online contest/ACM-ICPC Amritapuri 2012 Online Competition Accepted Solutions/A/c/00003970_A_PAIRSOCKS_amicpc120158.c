#include<stdio.h>
#include<string.h>
int main(){
	int tc;
	scanf("%d",&tc);
	char s[1000];
	while(tc>0){
		scanf("%s",s);
		int i=0;
		int r=0,g=0,w=0,b=0;
		while(s[i]!='\0')
		{
			if(s[i]=='R'){
				r++;
			}
			else if(s[i]=='B'){
				b++;
			}
			else if(s[i]=='W'){
				w++;
			}
			else if(s[i]=='G'){
				g++;
			}
			i++;
		}
		if(r%2==0 && w%2==0 && b%2==0 && g%2==0){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		tc--;
	}
	return 0;
}

