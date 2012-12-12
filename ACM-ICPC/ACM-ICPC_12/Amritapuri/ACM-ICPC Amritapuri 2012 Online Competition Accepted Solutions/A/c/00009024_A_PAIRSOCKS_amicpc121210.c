#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char ar[1000];
	char re[1000];
	int c,i=0,x=0;
	int j,r=0,g=0,b=0,w=0;
	int rm,gm,wm,bm;
	int l,k;
	while(scanf("%s",ar)==1){
		if(i==0){
			c=(int)atoi(ar);
			k=c;
			i++;				
			}
		else{
			l=strlen(ar);
			for(j=0;j<l;j++)
			{
				if (ar[j]=='R'){
				r++;
				}
				else if(ar[j]=='W'){
				w++;
				}
				else if(ar[j]=='B'){
				b++;}
				else if(ar[j]=='G'){
				g++;}
				else{}
			}
			rm=r%2;
			wm=w%2;
			gm=g%2;
			bm=b%2;
			if((rm==0) && (wm==0) && (gm==0)&&(bm==0))
				re[x]='y';
			else
				re[x]='n';
			x++;				
			ar[0]='\0';
			r=b=w=g=0;
	}
}
for(i=0;i<k;i++){
if(re[i]=='y')
printf("YES\n");
else
printf("NO\n");
}
return 0;}
