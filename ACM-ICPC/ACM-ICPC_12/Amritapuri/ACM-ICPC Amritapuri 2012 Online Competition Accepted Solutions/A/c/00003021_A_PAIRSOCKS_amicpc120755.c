#include <stdio.h>
#include <string.h>
#define size 100
#define r 0
#define g 1
#define b 2
#define w 3
char str[size];

 int main(){
 int t,arr[4],i,flag=0;
 scanf("%d",&t);
 while(t--){
 memset(arr,0,sizeof(arr));
 flag=0;
 scanf("%s",str);
 for(i=0;str[i];i++){
 	if(str[i]=='R')
 	  arr[r]+=1;
 	else if(str[i]=='G')  
 	 arr[g]+=1;
 	else if(str[i]=='B') 
 	 arr[b]+=1;
 	else
 	 arr[w]+=1; 
 }
 for(i=0;i<4;i++)
  if(arr[i]%2){
   flag=1;
   break;
   }
 if(flag)  
  printf("NO\n");
 else
  printf("YES\n");
 }
 return 0;
 }
