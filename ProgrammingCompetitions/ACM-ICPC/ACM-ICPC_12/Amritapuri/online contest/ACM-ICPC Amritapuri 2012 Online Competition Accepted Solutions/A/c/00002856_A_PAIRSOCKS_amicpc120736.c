#include<stdio.h>
#include<string.h>
int main(){
int t;
char str[100], i,r,g,b,w;
scanf("%d",&t);
while(t--){
    i=0;r=0;g=0;b=0;w=0;
scanf("%s",str);
int len = strlen(str);
for(i=0; i<len;i++){

if(str[i] == 'R'){
r++;
}
if(str[i] == 'G'){
g++;
}
if(str[i] == 'B'){
b++;
}
if(str[i] == 'W'){
w++;
}

}

if(r%2==0 && g%2==0 && b%2 ==0 && w%2 == 0){
printf("YES\n");

}
else{

printf("NO\n");
}

}

return 0;
}
