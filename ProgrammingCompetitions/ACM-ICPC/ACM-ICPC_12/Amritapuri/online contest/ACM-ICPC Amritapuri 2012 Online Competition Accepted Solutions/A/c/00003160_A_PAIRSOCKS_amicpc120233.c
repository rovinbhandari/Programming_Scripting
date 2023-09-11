#include<stdio.h>
#include<string.h>
int main(){
int t,i,r,w,b,g;
char a[51];
scanf("%d",&t);
while(t--){
scanf("%s",a);
r=0;
w=0;
b=0;
g=0;
for(i=0;i<strlen(a);++i){
                    if(a[i]=='R')
                                 r++; 
                    else if(a[i]=='G')
                         g++;
                    else if(a[i]=='W')
                         w++;
                    else if(a[i]=='B')
                         b++;
                         }
                         //printf("%d %d %d %d",r,g,b,w);
                         if(!(r%2) && !(b%2) && !(g%2) && !(w%2))
                                  printf("YES\n");
                         else
                             printf("NO\n");
           }
return 0;
}
