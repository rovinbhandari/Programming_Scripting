#include<stdio.h>
int main(){
    int i,j,t,r,g,w,b;
    char c,d;
    scanf("%d",&t);
    scanf("%c",&c);
    while(t--){
        c="&",r=0,g=0,w=0,b=0;
        scanf("%c",&c);
        while(c!='\n'){

               // printf(" char=%c ",c);
                if(c=='R')r++;
                else if(c=='G')g++;
                else if(c=='B')b++;
                else if(c=='W')w++;
                scanf("%c",&c);

            }
        if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))printf("YES\n");
        else printf("NO\n");
    }
    return 0;

}
