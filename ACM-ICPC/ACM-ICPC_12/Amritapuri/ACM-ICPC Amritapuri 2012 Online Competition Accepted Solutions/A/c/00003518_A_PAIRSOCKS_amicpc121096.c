#include<stdio.h>
#include<string.h>

int main(){
    int r, g, w,b,i,n;
    int T;
    char c, x[55];
    scanf("%d",&T);
    while(T-->0){
        
        r=g=w=b=0;
            
        scanf("%s",x);
        n = strlen(x);
       for(i=0;i<n;i++){
           c=x[i];
        switch(c){
            case 'R': r = 1-r; break;
            case 'B':b=1-b;break;
            case 'G':g=1-g;break;
            case 'W':w=1-w;break;
            
        }
       
        }
        
        if(r==0&&b==0&&w==0&&g==0){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}