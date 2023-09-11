#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int a[4]={0},i,c=0;
unsigned int t;
char input[50];
scanf("%u",&t);
for(;t--;)
{a[0]=a[1]=a[2]=a[3]=0;
scanf("%s",input);
if((strlen(input))%2!=0){
	printf("NO\n");
	
}
else{
	for(i=0;input[i]!='\0';i++){
		if(input[i]=='R')
			a[0]++;

		if(input[i]=='G')
			a[1]++;

		if(input[i]=='B')
			a[2]++;

		if(input[i]=='W')
			a[3]++;

	}//end of for	

c=0;
for(i=0;i<4;i++){
	if(a[i]%2==0) 
		c++;
	else 
		{printf("NO\n");break;}
}
if(c==4) printf("YES\n");
}}
return 0;
}
